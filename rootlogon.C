// This file is used for quick check with ROOT6 interpreter
{
   gInterpreter->AddIncludePath("include");
   
   gSystem->Load("lib/libErrorHandler.so");
   gSystem->Load("lib/libStrTools.so");
   gSystem->Load("lib/libIOTools.so");
   gSystem->Load("lib/libBox.so");
   gSystem->Load("lib/libTable.so");
   gSystem->Load("lib/libTime.so");
}
