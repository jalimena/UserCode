#ifndef DATAFORMATS_HCALDETID_HCALDETID_H
#define DATAFORMATS_HCALDETID_HCALDETID_H 1

#include <iosfwd>
#include "DetId.h"
#include "HcalSubdetector.h"


/** \class HcalDetId
 *  Cell identifier class for the HCAL subdetectors, precision readout cells only
 *
 *  $Date: 2013/06/17 20:28:00 $
 *  $Revision: 1.1 $
 *  \author J. Mans - Minnesota
 *
 *  Rev.1.11: A.Kubik,R.Ofierzynski: add the hashed_index
 */
class HcalDetId : public DetId {
public:
  /** Create a null cellid*/
  HcalDetId();
  /** Create cellid from raw id (0=invalid tower id) */
  HcalDetId(uint32_t rawid);
  /** Constructor from subdetector, signed tower ieta,iphi,and depth */
  HcalDetId(HcalSubdetector subdet, int tower_ieta, int tower_iphi, int depth);
  /** Constructor from a generic cell id */
  HcalDetId(const DetId& id);
  /** Assignment from a generic cell id */
  HcalDetId& operator=(const DetId& id);

  /// get the subdetector
  HcalSubdetector subdet() const { return (HcalSubdetector)(subdetId()); }
  /// get the z-side of the cell (1/-1)
  int zside() const { return (id_&0x2000)?(1):(-1); }
  /// get the absolute value of the cell ieta
  int ietaAbs() const { return (id_>>7)&0x3f; }
  /// get the cell ieta
  int ieta() const { return zside()*ietaAbs(); }
  /// get the cell iphi
  int iphi() const { return id_&0x7F; }
  /// get the tower depth
  int depth() const { return (id_>>14)&0x1F; }
  /// get the smallest crystal_ieta of the crystal in front of this tower (HB and HE tower 17 only)
  int crystal_ieta_low() const { return ((ieta()-zside())*5)+zside(); }
  /// get the largest crystal_ieta of the crystal in front of this tower (HB and HE tower 17 only)
  int crystal_ieta_high() const { return ((ieta()-zside())*5)+5*zside(); }
  /// get the smallest crystal_iphi of the crystal in front of this tower (HB and HE tower 17 only)
  int crystal_iphi_low() const; 
  /// get the largest crystal_iphi of the crystal in front of this tower (HB and HE tower 17 only)
  int crystal_iphi_high() const;

  static bool validDetId( HcalSubdetector subdet,
			  int             tower_ieta,
			  int             tower_iphi,
			  int             depth       ) ;

  // get the hashed index
  int hashed_index() const;

  uint32_t denseIndex() const { return hashed_index() ; }

  static bool validDenseIndex( uint32_t din ) { return ( din < kSizeForDenseIndexing ) ; }

  static HcalDetId detIdFromDenseIndex( uint32_t di ) ;

  static const HcalDetId Undefined;

   private:

      enum { kHBhalf = 1296 ,
	     kHEhalf = 1296 ,
	     kHOhalf = 1080 ,
	     kHFhalf = 864  ,
	     kHcalhalf = kHBhalf + kHEhalf + kHOhalf + kHFhalf } ;

   public:

      enum { kSizeForDenseIndexing = 2*kHcalhalf } ;
      enum { kHBSize = 2*kHBhalf } ;
      enum { kHESize = 2*kHEhalf } ;
      enum { kHOSize = 2*kHOhalf } ;
      enum { kHFSize = 2*kHFhalf } ;

};

std::ostream& operator<<(std::ostream&,const HcalDetId& id);

#endif
