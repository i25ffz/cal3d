# Microsoft Developer Studio Project File - Name="Cal3D_Cally" - Package Owner=<4>

# Microsoft Developer Studio Generated Build File, Format Version 6.00

# ** NICHT BEARBEITEN **



# TARGTYPE "Win32 (x86) Console Application" 0x0103



CFG=Cal3D_Cally - Win32 Debug

!MESSAGE Dies ist kein g�ltiges Makefile. Zum Erstellen dieses Projekts mit NMAKE

!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und f�hren Sie den Befehl

!MESSAGE 

!MESSAGE NMAKE /f "cal3d_cally.mak".

!MESSAGE 

!MESSAGE Sie k�nnen beim Ausf�hren von NMAKE eine Konfiguration angeben

!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:

!MESSAGE 

!MESSAGE NMAKE /f "cal3d_cally.mak" CFG="Cal3D_Cally - Win32 Debug"

!MESSAGE 

!MESSAGE F�r die Konfiguration stehen zur Auswahl:

!MESSAGE 

!MESSAGE "Cal3D_Cally - Win32 Release" (basierend auf  "Win32 (x86) Console Application")

!MESSAGE "Cal3D_Cally - Win32 Debug" (basierend auf  "Win32 (x86) Console Application")

!MESSAGE 



# Begin Project

# PROP AllowPerConfigDependencies 0

# PROP Scc_ProjName ""

# PROP Scc_LocalPath ""

CPP=cl.exe

RSC=rc.exe



!IF  "$(CFG)" == "Cal3D_Cally - Win32 Release"



# PROP BASE Use_MFC 0

# PROP BASE Use_Debug_Libraries 0

# PROP BASE Output_Dir "Release"

# PROP BASE Intermediate_Dir "Release"

# PROP BASE Target_Dir ""

# PROP Use_MFC 0

# PROP Use_Debug_Libraries 0

# PROP Output_Dir "Release"

# PROP Intermediate_Dir "Release"

# PROP Ignore_Export_Lib 0

# PROP Target_Dir ""

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c

# ADD CPP /nologo /W3 /GX /O2 /I "..\cal3d\src\cal3d" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c

# ADD BASE RSC /l 0x807 /d "NDEBUG"

# ADD RSC /l 0x807 /d "NDEBUG"

BSC32=bscmake.exe

# ADD BASE BSC32 /nologo

# ADD BSC32 /nologo

LINK32=link.exe

# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

# ADD LINK32 Cal3D.lib glut32.lib glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /libpath:"..\cal3d\Release"

# SUBTRACT LINK32 /profile /debug



!ELSEIF  "$(CFG)" == "Cal3D_Cally - Win32 Debug"



# PROP BASE Use_MFC 0

# PROP BASE Use_Debug_Libraries 1

# PROP BASE Output_Dir "Debug"

# PROP BASE Intermediate_Dir "Debug"

# PROP BASE Target_Dir ""

# PROP Use_MFC 0

# PROP Use_Debug_Libraries 1

# PROP Output_Dir "Debug"

# PROP Intermediate_Dir "Debug"

# PROP Ignore_Export_Lib 0

# PROP Target_Dir ""

# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c

# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\cal3d\src\cal3d" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c

# ADD BASE RSC /l 0x807 /d "_DEBUG"

# ADD RSC /l 0x807 /d "_DEBUG"

BSC32=bscmake.exe

# ADD BASE BSC32 /nologo

# ADD BSC32 /nologo

LINK32=link.exe

# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

# ADD LINK32 Cal3D.lib glut32.lib glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\cal3d\Debug"



!ENDIF 



# Begin Target



# Name "Cal3D_Cally - Win32 Release"

# Name "Cal3D_Cally - Win32 Debug"

# Begin Group "Quellcodedateien"



# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"

# Begin Source File



SOURCE=.\src\demo.cpp

# End Source File

# Begin Source File



SOURCE=.\src\main.cpp

# End Source File

# Begin Source File



SOURCE=.\src\menu.cpp

# End Source File

# Begin Source File



SOURCE=.\src\model.cpp

# End Source File

# Begin Source File



SOURCE=.\src\tick.cpp

# End Source File

# End Group

# Begin Group "Header-Dateien"



# PROP Default_Filter "h;hpp;hxx;hm;inl"

# Begin Source File



SOURCE=.\config.h

# End Source File

# Begin Source File



SOURCE=.\src\demo.h

# End Source File

# Begin Source File



SOURCE=.\src\global.h

# End Source File

# Begin Source File



SOURCE=.\src\menu.h

# End Source File

# Begin Source File



SOURCE=.\src\model.h

# End Source File

# Begin Source File



SOURCE=.\src\tick.h

# End Source File

# Begin Source File



SOURCE=.\src\tga.h

# End Source File

# Begin Source File


SOURCE=.\src\tga.cpp

# End Source File


# End Group


# Begin Group "Ressourcendateien"



# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"

# End Group

# Begin Source File



SOURCE=.\AUTHORS

# End Source File

# Begin Source File



SOURCE=.\ChangeLog

# End Source File

# Begin Source File



SOURCE=.\COPYING

# End Source File

# Begin Source File



SOURCE=.\INSTALL

# End Source File

# Begin Source File



SOURCE=.\README

# End Source File

# Begin Source File



SOURCE=.\TODO

# End Source File

# End Target

# End Project

