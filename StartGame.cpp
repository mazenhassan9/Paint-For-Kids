#include"GUI/GUI.h"
#include"StartGame.h"
#include"controller.h"
#include"Shapes/Graph.h"

StartGame::StartGame(controller* pCont) :operation(pCont)
{
}

StartGame::~StartGame()
{
}

void StartGame::Execute()
{

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	string filename = "SavedGraph.txt";
	ofstream file;
	file.open(filename, ios::out);
	pGr->Save(file);
	file.close();
	pUI->PrintMessage("Starting Game");
	pGr->DuplicateGraph();
	pGr->ScrambleGraph();
	pGr->HideAll(true);

}
