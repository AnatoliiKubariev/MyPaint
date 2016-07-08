#include "UndoRedoStack.h"

void UndoRedoStack::Register(std::unique_ptr<GraphicsCommand> command)
{
    if(m_current_item > (m_commands.size() - 1))
    {
        m_commands.resize(m_current_item + 1);
    }
    m_commands.push_back(std::move(command));
    ++m_current_item;
}

void UndoRedoStack::ReDo()
{
    if(m_current_item >= (static_cast<int>(m_commands.size()) - 1))
    {
        return;
    }
    ++m_current_item;
    m_commands[m_current_item]->ReDo();
}

void UndoRedoStack::UnDo()
{
    if(m_current_item < 0)
    {
        return;
    }
    m_commands[m_current_item]->UnDo();
    --m_current_item;
}