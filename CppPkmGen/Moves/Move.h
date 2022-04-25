#pragma once
class Move
{
	int power;
	int accuracy;
	const char* type;
	virtual void damage() = 0;
	virtual void special() = 0;
};

