#include "Circle.h"
#include <iostream>
Circle::Circle()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;
	center.x = 0;
	center.y = 0;
	radius = 0;

}
Circle::Circle(Point circenter, int radius, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = circenter;
	this->radius = radius;
}

Circle::Circle(const Circle* lhs) 
{
	this->ID = lhs->ID;
	this->center.x = lhs->center.x;
	this->center.y = lhs->center.y;
	this->radius = lhs->radius;
	this->ShpGfxInfo.DrawClr = lhs->ShpGfxInfo.DrawClr;
	this->ShpGfxInfo.FillClr = lhs->ShpGfxInfo.FillClr;
	this->ShpGfxInfo.isFilled = lhs->ShpGfxInfo.isFilled;
	this->ShpGfxInfo.BorderWdth = lhs->ShpGfxInfo.BorderWdth;
	this->ShpGfxInfo.isSelected = false;

}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pUI->DrawCir(center, radius, ShpGfxInfo);
}

void Circle::stick(GUI* pUI) const
{
	int x = center.x - radius;
	int y = center.y - radius;
	string img = "images\\MenuIcons\\Menu_Circle.jpg";
	pUI->DrawImg(img,x,y,(2*radius),(2*radius));
	
}



bool Circle::Get(int x, int y) const
{

	int pDistance = sqrt(pow((center.x - x), 2) + pow((center.y - y), 2));

	if (pDistance <= radius)
		return true;

	return false;
}

void Circle::Move(int x, int y)
{
	this->center.x = x;
	this->center.y = y;
	
}

void Circle::Rotate()
{

	// get the center point location 
	double x1, x2, y1, y2;
	int centerx, centery;
	centerx = center.x ;
	centery = center.y ;


	double PI = 3.14;



	x1 = center.x - centerx;
	y1 = center.y - centery;


	this->center.x = (x1 * cos(PI / 2) - y1 * sin(PI / 2)) + centerx;	
	this->center.y = (x1 * sin(PI / 2) + y1 * cos(PI / 2)) + centery;
	






}

string Circle::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";
	ShpGfxInfo.DrawClr.ucRed;

	string message = "Circle   " + to_string(ID) + "    Center (" + to_string(center.x) + " , " + to_string(center.y)
		+ ")   Radius= " + to_string(radius)
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

void Circle::Save(ofstream& OutFile)
{
	
	OutFile << "CIRCLE  " << ID << "  " << center.x << "  " << center.y << "  " << radius;
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile << "True" << "  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void Circle::Load(ifstream& Infile)
{
	int D1, D2, D3;
	int F1, F2, F3;

	Infile >> ID >> center.x >> center.y >> radius;
	Infile >> D1 >> D2 >> D3;
	color C1(D1, D2, D3);
	ShpGfxInfo.DrawClr = C1;
	string conditon;
	Infile >> conditon;
	if (conditon == "True")
	{
		ShpGfxInfo.isFilled = true;
		Infile >> F1 >>F2 >> F3;
		color C2(F1, F2, F3);
		ShpGfxInfo.FillClr = C2;
	}
	else
	{
		ShpGfxInfo.isFilled = false;
	}
}
void Circle::RESIZE(double size) 
{
	

	radius *= size;
}

shape* Circle::Copy()
{
	shape* S = new Circle(this);
	return S;
}
void Circle::mapshape(GUI* pUI)
{
	Point Corner = { center.x + radius,center.y };
	pUI->Mapx(center.x);
	pUI->Mapx(Corner.x);
	pUI->Mapy(center.y);
	pUI->Mapy(Corner.y);
}





Point Circle::GetFirstPoint() const
{
	int x = center.x - radius;
	int y = center.y - radius;
	Point P1 = { x,y };
	return P1;
}
