#pragma once

#include <utils/id.h>
#include <utils/optional.h>

#include <QObject>
#include <QString>
#include <QWidget>

namespace Utils {
    class FilePath;
}

namespace XMakeProjectManager::Internal {
    namespace Ui {
        class ToolItemSettings;
    }

    class ToolTreeItem;
    class ToolItemSettings: public QWidget {
        Q_OBJECT

      public:
        explicit ToolItemSettings(QWidget *parent = nullptr);

        void load(ToolTreeItem *item);
        void store();

      Q_SIGNALS:
        void
            applyChanges(const Utils::Id &item_id, const QString &name, const Utils::FilePath &exe);

      private:
        std::unique_ptr<Ui::ToolItemSettings> m_ui;

        Utils::optional<Utils::Id> m_current_id = Utils::nullopt;
    };
} // namespace XMakeProjectManager::Internal
