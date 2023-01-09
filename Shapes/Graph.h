#pragma once
#include "Shape.h"
#include "Group.h"
#include <fstream>
#include <vector>


using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	vector<shape*> selectedShapes;	//pointer to the currently selected shape
	vector<Group*> grouplist;
	vector<operationType> operations; 
	vector<shape*> copiedshapes;
	vector<shape*>deletedShapes, modifiedShapes; 
	//undo variables
	vector<operationType> UndoOperations;
	vector<shape*>deletedShapesUndo, modifiedShapesUndo;
	int score = 0;
	
public:										
	Graph();
	~Graph();
	void AddOperation(operationType op);
	
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void AddsGroup(Group* pShp);
	void DeleteShape(shape* pFig);
	void DeleteGroup(Group* pFig);
	void SetSelected(shape* pFig,bool flag); //set Selected pointer to a select.
	vector<shape*> GetSelected();
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	vector <shape*> getlistofshspes();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	vector<shape*> getcopied()const;
	void clearCopied();
	void setcopied(shape* cs);
	void mapshapes(GUI* pUI);
	shape* GetLastSelected() const;
	operationType GetlastOperation();
	shape* GetLastAdded();
	shape* GetLastDeleted();	//shapes before deleted.
	shape* GetLastModified(); //shapes state before modification
	void AddDeletedShape(shape*pShp, bool s);
	void AddModifiedShape(shape* pShp, bool s);
	void SendBack(shape* pFig);
	void HideAll(bool s);
	void DuplicateGraph();
	void ScrambleGraph();
	bool UnHideone(int x, int y, GUI* pGUI);
	int matchshapes();
	void resetscore();
	int getscore() const;
	//Redo Functions
	void AddOperationUndo(operationType op);
	void isalldone(GUI* pUI);
	operationType GetLastUndo();
	shape* GetLastDeletedUndo();	//shapes before deleted.
	shape* GetLastModifiedUndo();
	void AddDeletedShapeUndo(shape* pShp, bool s);
	void AddModifiedShapeUndo(shape* pShp, bool s);
};
