#pragma once

#include "ToolTreeItem.hpp"

#include <utils/treemodel.h>

namespace XMakeProjectManager::Internal {
    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    inline auto ToolTreeItem::name() const noexcept -> const QString & { return m_name; }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    inline auto ToolTreeItem::executable() const noexcept -> const Utils::FilePath & {
        return m_executable;
    }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    inline auto ToolTreeItem::isAutoDetected() const noexcept -> bool { return m_auto_detected; }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    inline auto ToolTreeItem::id() const noexcept -> const Utils::Id & { return m_id; }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    inline auto ToolTreeItem::hasUnsavedChanges() const noexcept -> bool {
        return m_unsaved_changes;
    }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    inline auto ToolTreeItem::setSaved() noexcept -> void { m_unsaved_changes = false; }
} // namespace XMakeProjectManager::Internal
