#pragma once

class GraphicsCommand
{
public:
    virtual ~GraphicsCommand() = 0 {}

    virtual void ReDo() = 0 {};
    virtual void UnDo() = 0 {};
};