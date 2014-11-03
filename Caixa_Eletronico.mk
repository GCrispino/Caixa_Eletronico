##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Caixa_Eletronico
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Crispino\Documents\ProgII"
ProjectPath            := "C:\Users\Crispino\Documents\ProgII\Caixa_Eletronico"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Crispino
Date                   :=11/03/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="Caixa_Eletronico.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe 
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
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe 
CC       := C:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Caixa_Eletronico.cpp$(ObjectSuffix) $(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IntermediateDirectory)/Conta.cpp$(ObjectSuffix) $(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) $(IntermediateDirectory)/Banco.cpp$(ObjectSuffix) $(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix) $(IntermediateDirectory)/Device.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Caixa_Eletronico.cpp$(ObjectSuffix): Caixa_Eletronico.cpp $(IntermediateDirectory)/Caixa_Eletronico.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/Caixa_Eletronico.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Caixa_Eletronico.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Caixa_Eletronico.cpp$(DependSuffix): Caixa_Eletronico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Caixa_Eletronico.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Caixa_Eletronico.cpp$(DependSuffix) -MM "Caixa_Eletronico.cpp"

$(IntermediateDirectory)/Caixa_Eletronico.cpp$(PreprocessSuffix): Caixa_Eletronico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Caixa_Eletronico.cpp$(PreprocessSuffix) "Caixa_Eletronico.cpp"

$(IntermediateDirectory)/Data.cpp$(ObjectSuffix): Data.cpp $(IntermediateDirectory)/Data.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Data.cpp$(DependSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Data.cpp$(DependSuffix) -MM "Data.cpp"

$(IntermediateDirectory)/Data.cpp$(PreprocessSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Data.cpp$(PreprocessSuffix) "Data.cpp"

$(IntermediateDirectory)/Conta.cpp$(ObjectSuffix): Conta.cpp $(IntermediateDirectory)/Conta.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/Conta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Conta.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Conta.cpp$(DependSuffix): Conta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Conta.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Conta.cpp$(DependSuffix) -MM "Conta.cpp"

$(IntermediateDirectory)/Conta.cpp$(PreprocessSuffix): Conta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Conta.cpp$(PreprocessSuffix) "Conta.cpp"

$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix): Usuario.cpp $(IntermediateDirectory)/Usuario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/Usuario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Usuario.cpp$(DependSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Usuario.cpp$(DependSuffix) -MM "Usuario.cpp"

$(IntermediateDirectory)/Usuario.cpp$(PreprocessSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Usuario.cpp$(PreprocessSuffix) "Usuario.cpp"

$(IntermediateDirectory)/Banco.cpp$(ObjectSuffix): Banco.cpp $(IntermediateDirectory)/Banco.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/Banco.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Banco.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Banco.cpp$(DependSuffix): Banco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Banco.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Banco.cpp$(DependSuffix) -MM "Banco.cpp"

$(IntermediateDirectory)/Banco.cpp$(PreprocessSuffix): Banco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Banco.cpp$(PreprocessSuffix) "Banco.cpp"

$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix): stringDigitos.cpp $(IntermediateDirectory)/stringDigitos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/stringDigitos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stringDigitos.cpp$(DependSuffix): stringDigitos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/stringDigitos.cpp$(DependSuffix) -MM "stringDigitos.cpp"

$(IntermediateDirectory)/stringDigitos.cpp$(PreprocessSuffix): stringDigitos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stringDigitos.cpp$(PreprocessSuffix) "stringDigitos.cpp"

$(IntermediateDirectory)/Device.cpp$(ObjectSuffix): Device.cpp $(IntermediateDirectory)/Device.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/Caixa_Eletronico/Device.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Device.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Device.cpp$(DependSuffix): Device.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Device.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Device.cpp$(DependSuffix) -MM "Device.cpp"

$(IntermediateDirectory)/Device.cpp$(PreprocessSuffix): Device.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Device.cpp$(PreprocessSuffix) "Device.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/Caixa_Eletronico"


