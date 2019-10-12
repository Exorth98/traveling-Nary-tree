##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SDDA_TD7-TD8
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/CAILLEUX/Documents/CodeLiteProjects
ProjectPath            :=C:/Users/CAILLEUX/Documents/CodeLiteProjects/SDDA_TD7-TD8
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=CAILLEUX
Date                   :=12/01/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SDDA_TD7-TD8.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/connexions.c$(ObjectSuffix) $(IntermediateDirectory)/arbre.c$(ObjectSuffix) $(IntermediateDirectory)/villes.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/CAILLEUX/Documents/CodeLiteProjects/SDDA_TD7-TD8/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/connexions.c$(ObjectSuffix): connexions.c $(IntermediateDirectory)/connexions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/CAILLEUX/Documents/CodeLiteProjects/SDDA_TD7-TD8/connexions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/connexions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/connexions.c$(DependSuffix): connexions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/connexions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/connexions.c$(DependSuffix) -MM connexions.c

$(IntermediateDirectory)/connexions.c$(PreprocessSuffix): connexions.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/connexions.c$(PreprocessSuffix) connexions.c

$(IntermediateDirectory)/arbre.c$(ObjectSuffix): arbre.c $(IntermediateDirectory)/arbre.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/CAILLEUX/Documents/CodeLiteProjects/SDDA_TD7-TD8/arbre.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/arbre.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/arbre.c$(DependSuffix): arbre.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/arbre.c$(ObjectSuffix) -MF$(IntermediateDirectory)/arbre.c$(DependSuffix) -MM arbre.c

$(IntermediateDirectory)/arbre.c$(PreprocessSuffix): arbre.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/arbre.c$(PreprocessSuffix) arbre.c

$(IntermediateDirectory)/villes.c$(ObjectSuffix): villes.c $(IntermediateDirectory)/villes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/CAILLEUX/Documents/CodeLiteProjects/SDDA_TD7-TD8/villes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/villes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/villes.c$(DependSuffix): villes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/villes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/villes.c$(DependSuffix) -MM villes.c

$(IntermediateDirectory)/villes.c$(PreprocessSuffix): villes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/villes.c$(PreprocessSuffix) villes.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


