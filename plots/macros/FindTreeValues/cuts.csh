#!/bin/tcsh

set BxCut = wBxCut
set CavernCut = wCavernCut
set GeneratorMuonCut = wGeneratorMuonCut 
set SACut = wSACut 
set GenMuonMatchedCut = woGenMuonMatchedCut 
set TriggerCut = wTriggerCut 
set PtCut = wPtCut 
set ChaCut = wChaCut 
set EtaCut = wEtaCut 
#set UpperCut = woUpperCut 
set UpperCut = wUpperCut 
set RpcCut = wRpcCut 
set RpcBxCut = woRpcBxCut
#set RpcBxCut = wRpcBxCut
set DtHitsCut = wDtHitsCut 
#set DtInvBetaCut = wDtInvBetaCut 
set DtInvBetaCut = woDtInvBetaCut 
#set TimeInOutCut = wTimeInOutCut
set TimeInOutCut = woTimeInOutCut
#set OppEtaCut = wOppEtaCut 
set OppEtaCut = woOppEtaCut 
set TightPhi = woTightPhi
#set resT3 = res
set resT3 = T3
set Printout = woPrintout
#set Printout = wPrintout

if ($Printout == "woPrintout") then
    set cuts_ = $BxCut"_"$CavernCut"_"$GeneratorMuonCut"_"$SACut"_"$GenMuonMatchedCut"_"$TriggerCut"_"$PtCut"_"$ChaCut"_"$EtaCut"_"$UpperCut"_"$RpcCut"_"$RpcBxCut"_"$DtHitsCut"_"$DtInvBetaCut"_"$TimeInOutCut"_"$OppEtaCut"_"$TightPhi
else
    set cuts_ = $Printout    
endif

set cuts = "$BxCut $CavernCut $GeneratorMuonCut $SACut $GenMuonMatchedCut $TriggerCut $PtCut $ChaCut $EtaCut $UpperCut $RpcCut $RpcBxCut $DtHitsCut $DtInvBetaCut $TimeInOutCut $OppEtaCut $TightPhi $resT3 $Printout"

