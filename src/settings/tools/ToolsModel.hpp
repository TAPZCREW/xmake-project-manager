#pragma once

#include <settings/tools/ToolsSettingsPage.hpp>

#include <utils/treemodel.h>

#include <QQueue>

namespace XMakeProjectManager::Internal {
    class ToolTreeItem;
    class XMakeWrapper;
    class ToolsModel final
        : public Utils::TreeModel<Utils::TreeItem, Utils::TreeItem, ToolTreeItem> {
        Q_DECLARE_TR_FUNCTIONS(XMakeProjectManager::Internal::ToolsSettingsPage)

      public:
        ToolsModel();
        ~ToolsModel() override;

        ToolsModel(ToolsModel &&)      = delete;
        ToolsModel(const ToolsModel &) = delete;

        ToolsModel &operator=(ToolsModel &&) = delete;
        ToolsModel &operator=(const ToolsModel &) = delete;

        ToolTreeItem *xmakeToolTreeItem(const QModelIndex &index) const;

        void updateItem(const Utils::Id &item_id, const QString &name, const Utils::FilePath &exe);

        void addXMakeTool();
        void removeXMakeTool(ToolTreeItem *item);
        ToolTreeItem *cloneXMakeTool(ToolTreeItem *item);

        void apply();

      private:
        void addXMakeTool(const XMakeWrapper &tool);

        QString uniqueName(const QString &base_name);

        Utils::TreeItem *autoDetectedGroup() const;
        Utils::TreeItem *manualGroup() const;

        QQueue<Utils::Id> m_items_to_remove;
    };
    ;
} // namespace XMakeProjectManager::Internal
