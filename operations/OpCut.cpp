#include "OpCut.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
opCut::opCut(controller* pCont):operation(pCont)
{
}

opCut::~opCut()
{
}

void opCut::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	vector<shape*> Shapes = pGr->GetSelected();
	shape* S1 = pGr->GetLastSelected();

	if (S1)
	{
	

		for (auto& itr : Shapes)
		{
			shape* S2 = itr->Copy();
			pGr->DeleteShape(itr);
			pGr->setcopied(S2);

		}


		pUI->PrintMessage("Cut Operation, All Selected shapes has been Cut");

	}
	else
		pUI->PrintMessage("No Shape Selected, Please select a shape");
}
