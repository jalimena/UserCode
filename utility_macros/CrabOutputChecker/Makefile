CXX           = g++
CXXFLAGS      = $(OPT2) -m64 -pipe -Wall -W -Woverloaded-virtual -g 
LD            = g++
SOFLAGS       = -dynamiclib -single_module -undefined $(UNDEFOPT)
LDFLAGS       = -g
SOFLAGS       = -shared

#ROOTINCLUDES = -I$(CMS_PATH)/slc5_amd64_gcc434/lcg/root/5.27.06b-cms23/include/
#ROOTLDLIBS   = -L$(CMS_PATH)/slc5_amd64_gcc434/lcg/root/5.27.06b-cms23/lib/ -lPhysics -lEG -lMathCore -lHist -lTree -lNet -lRIO -lCore
#ROOTINCLUDES = -I$(CMS_PATH)/slc5_amd64_gcc462/lcg/root/5.32.00-cms9/include/
#ROOTLDLIBS   = -L$(CMS_PATH)/slc5_amd64_gcc462/lcg/root/5.32.00-cms9/lib/ -lPhysics -lEG -lMathCore -lHist -lTree -lNet -lRIO -lCore -lCint
ROOTINCLUDES = -I$(CMS_PATH)/slc5_amd64_gcc462/lcg/root/5.32.00-cms21/include/
ROOTLDLIBS   = -L$(CMS_PATH)/slc5_amd64_gcc462/lcg/root/5.32.00-cms21/lib/ -lPhysics -lEG -lMathCore -lHist -lTree -lNet -lRIO -lCore -lCint

INCLUDES = 	 $(ROOTINCLUDES)
LDLIBS = -L.  	 $(ROOTLDLIBS)

all : crabOutput
	@echo Build $@
clean:
	rm -rf crabOutputChecker

crabOutput : crabOutputChecker.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) 	 $^ $(LDLIBS) -o crabOutputChecker
