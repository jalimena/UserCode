#!/bin/tcsh

set BxCut = wBxCut
set CavernCut = wCavernCut
set GeneratorMuonCut = wGeneratorMuonCut 
#set GeneratorMuonCut = woGeneratorMuonCut 
set SACut = wSACut 
set GenMuonMatchedCut = woGenMuonMatchedCut 
#set GenMuonMatchedCut = wGenMuonMatchedCut 
set TriggerCut = wTriggerCut 
#set TriggerCut = woTriggerCut 
#set PtCut = wPtCut 
set PtCut = woPtCut 
#set ChaCut = wChaCut 
set ChaCut = woChaCut 
#set EtaCut = wEtaCut 
set EtaCut = woEtaCut 
set UpperCut = woUpperCut 
#set UpperCut = wUpperCut 
#set RpcCut = wRpcCut 
set RpcCut = woRpcCut 
set RpcBxCut = woRpcBxCut
#set RpcBxCut = wRpcBxCut
#set DtHitsCut = wDtHitsCut 
set DtHitsCut = woDtHitsCut 
#set CscHitsCut = wCscHitsCut 
set CscHitsCut = woCscHitsCut 
#set DtInvBetaCut = wDtInvBetaCut 
set DtInvBetaCut = woDtInvBetaCut 
#set TimeInOutCut = wTimeInOutCut
set TimeInOutCut = woTimeInOutCut
#set OppEtaCut = wOppEtaCut 
set OppEtaCut = woOppEtaCut 
#set OppPhiCut = wOppPhiCut 
set OppPhiCut = woOppPhiCut 
set TightPhi = woTightPhi
#set CosmicEnriched = wCosmicEnriched
set CosmicEnriched = woCosmicEnriched
#set resT3 = res
set resT3 = T3
set Printout = woPrintout
#set Printout = wPrintout

if ($Printout == "woPrintout") then
    set cuts_ = $BxCut"_"$CavernCut"_"$GeneratorMuonCut"_"$SACut"_"$GenMuonMatchedCut"_"$TriggerCut"_"$PtCut"_"$ChaCut"_"$EtaCut"_"$UpperCut"_"$RpcCut"_"$RpcBxCut"_"$DtHitsCut"_"$CscHitsCut"_"$DtInvBetaCut"_"$TimeInOutCut"_"$OppEtaCut"_"$OppPhiCut"_"$TightPhi"_"$CosmicEnriched
else
    set cuts_ = $Printout    
endif

set cuts = "$BxCut $CavernCut $GeneratorMuonCut $SACut $GenMuonMatchedCut $TriggerCut $PtCut $ChaCut $EtaCut $UpperCut $RpcCut $RpcBxCut $DtHitsCut $CscHitsCut $DtInvBetaCut $TimeInOutCut $OppEtaCut $OppPhiCut $TightPhi $CosmicEnriched $resT3 $Printout"

