#include "OpRestart.h"
#include"../GUI/GUI.h"
#include"../controller.h"
#include"../Shapes/Graph.h"
#include"../StartGame.h"
OpRestart::OpRestart(controller* pCont):operation(pCont)
{
}

OpRestart::~OpRestart()
{
}

void OpRestart::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pGr->resetscore();
	string FileName = "SavedGraph.txt";
	ifstream File;
	File.open(FileName, ios::in);
	if (File.is_open())
	{
		pGr->load(File);
		File.close();
		operation* op = new StartGame(pControl);
		op->Execute();
		delete op;
	}
	else
	{
		pUI->PrintMessage("You Have to Play at least 1 time before restart");
	}
}
