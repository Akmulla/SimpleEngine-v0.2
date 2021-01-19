#pragma once

class InputData
{
public: 
	float horizontal;
	float vertical;
};

class Input
{
private:
	static InputData input;
public:
	static const InputData& GetInput();
	static void SetVerticalAxis(float);
	static void SetHorizontalAxis(float);
};