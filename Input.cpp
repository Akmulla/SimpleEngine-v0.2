#include "Input.h"

InputData Input::input;

const InputData& Input::GetInput()
{
    return input;
}

void Input::SetVerticalAxis(float y)
{
    input.vertical = y;
}

void Input::SetHorizontalAxis(float x)
{
    input.horizontal = x;
}
