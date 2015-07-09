
#include "GeneratorInterface/Core/interface/GeneratorFilter.h"
#include "GeneratorInterface/ExternalDecays/interface/ExternalDecayDriver.h"

#include "GeneratorInterface/Pythia8Interface/interface/Py8GunBase.h"

namespace gen {

class Py8PGun : public Py8GunBase {
   
   public:
      
      Py8PGun( edm::ParameterSet const& );
      ~Py8PGun() {}
	 
      bool generatePartonsAndHadronize() override;
      const char* classname() const override;
	 
   private:
      
      // PtGun particle(s) characteristics
      double  fMinEta;
      double  fMaxEta;
      double  fMinP;
      double  fMaxP;
      bool    fAddAntiParticle;

};

// implementation 
//
Py8PGun::Py8PGun( edm::ParameterSet const& ps )
   : Py8GunBase(ps) 
{

   // ParameterSet defpset ;
   edm::ParameterSet pgun_params = 
      ps.getParameter<edm::ParameterSet>("PGunParameters"); // , defpset ) ;
   fMinEta     = pgun_params.getParameter<double>("MinEta"); // ,-2.2);
   fMaxEta     = pgun_params.getParameter<double>("MaxEta"); // , 2.2);
   fMinP       = pgun_params.getParameter<double>("MinP"); // ,  0.);
   fMaxP       = pgun_params.getParameter<double>("MaxP"); // ,  0.);
   fAddAntiParticle = pgun_params.getParameter<bool>("AddAntiParticle"); //, false) ;  

}

bool Py8PGun::generatePartonsAndHadronize()
{

   fMasterGen->event.reset();
   
   for ( size_t i=0; i<fPartIDs.size(); i++ )
   {

      int particleID = fPartIDs[i]; // this is PDG - need to convert to Py8 ???

      double phi = (fMaxPhi-fMinPhi) * randomEngine().flat() + fMinPhi;
      double eta  = (fMaxEta-fMinEta) * randomEngine().flat() + fMinEta;
      double the  = 2.*atan(exp(-eta));

      double pp   = (fMaxP-fMinP) * randomEngine().flat() + fMinP;
      
      double mass = (fMasterGen->particleData).m0( particleID );

      double pt = pp * sin(the); 
      double ee = sqrt( pp*pp + mass*mass );
      
      double px = pt * cos(phi);
      double py = pt * sin(phi);
      double pz = pp * cos(the);

      if ( !((fMasterGen->particleData).isParticle( particleID )) )
      {
         particleID = std::fabs(particleID) ;
      }
      (fMasterGen->event).append( particleID, 1, 0, 0, px, py, pz, ee, mass ); 

// Here also need to add anti-particle (if any)
// otherwise just add a 2nd particle of the same type 
// (for example, gamma)
//
      if ( fAddAntiParticle )
      {
         if ( (fMasterGen->particleData).isParticle( -particleID ) )
	 {
	    (fMasterGen->event).append( -particleID, 1, 0, 0, -px, -py, -pz, ee, mass );
	 }
	 else
	 {
	    (fMasterGen->event).append( particleID, 1, 0, 0, -px, -py, -pz, ee, mass );
	 }
      }

   }
   
   if ( !fMasterGen->next() ) return false;
   
   event().reset(new HepMC::GenEvent);
   return toHepMC.fill_next_event( fMasterGen->event, event().get() );
  
}

const char* Py8PGun::classname() const
{
   return "Py8PGun"; 
}

typedef edm::GeneratorFilter<gen::Py8PGun, gen::ExternalDecayDriver> Pythia8PGun;

} // end namespace

using gen::Pythia8PGun;
DEFINE_FWK_MODULE(Pythia8PGun);
