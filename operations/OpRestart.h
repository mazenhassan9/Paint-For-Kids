#pragma once

#include "../operations/operation.h"


class OpRestart : public operation
{
public:
	OpRestart(controller* pCont);
	virtual ~OpRestart();

	virtual void Execute();

};
#pragma once
