#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

#include"opCopy.h"

opCopy::opCopy(controller* pCont) :operation(pCont)
{
}

opCopy::~opCopy()
{
}
void opCopy::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();
	vector<shape*> Shapes = pGr->GetSelected();
	if (S1)
	{
		for (auto& itr : Shapes)
		{
			shape* S2 = itr->Copy();
			pGr->setcopied(S2);

		}
		
		
		pUI->PrintMessage("Copy Operation, All Selected shapes has been copied");
		

	}
	else
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");

}