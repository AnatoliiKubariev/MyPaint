#include "UndoRedoStack.h"

void UndoRedoStack::Register(std::unique_ptr<GraphicsCommand> command)
{
    if(m_top < (m_commands.size() - 1)) //resize stack by new top
    {
        m_commands.resize(m_top + 1);
    }
    m_commands.push_back(std::move(command));
    ++m_top;
}

void UndoRedoStack::ReDo()
{
    if(m_top >= (static_cast<int>(m_commands.size()) - 1)) //return if top - last element
    {
        return;
    }
    ++m_top;
    m_commands[m_top]->ReDo();
}

void UndoRedoStack::UnDo()
{
    if(m_top == 0)
    {
        return;
    }
    m_commands[m_top]->UnDo();
    --m_top;
}