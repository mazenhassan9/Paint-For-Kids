#include "opPaste.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
opPaste::opPaste(controller* pCont) :operation(pCont)
{
}

opPaste::~opPaste()
{
}

void opPaste::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	vector<shape*> Shapes= pGr->getcopied();
	Point P1;

	int i = 0;
	for (auto& itr : Shapes)
	{
		pUI->PrintMessage("Paste operation : Click a point "+to_string(i));
		pUI->GetPointClicked(P1.x, P1.y);
		shape* S2 = itr->Copy();
		S2->Move(P1.x, P1.y);
		pGr->Addshape(S2);
		i++;
	}
	pUI->PrintMessage("Paste Operation, All Selected shapes has been pasted");
	pGr->clearCopied();
	

}
