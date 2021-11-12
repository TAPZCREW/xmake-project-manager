#pragma once

#include <QObject>
#include <QString>

#include <utils/fileutils.h>
#include <utils/id.h>

#include <memory>
#include <span>

namespace XMakeProjectManager::Internal {
    class XMakeWrapper;
    class XMakeTools: public QObject {
        Q_OBJECT

      public:
        using XMakeWrapperPtr = std::unique_ptr<XMakeWrapper>;

        ~XMakeTools() override;

        static void addTool(Utils::Id id, QString name, Utils::FilePath exe);
        static void addTool(XMakeWrapperPtr &&xmake);
        static void setTools(std::vector<XMakeWrapperPtr> &&tools);
        static void updateTool(Utils::Id id, QString name, Utils::FilePath exe);
        static void removeTool(Utils::Id id);

        static std::span<const XMakeWrapperPtr> tools() noexcept;

        static XMakeWrapper *xmakeWrapper();
        static XMakeWrapper *xmakeWrapper(Utils::Id id);

        static XMakeTools &instance();
      Q_SIGNALS:
        void toolAdded(const XMakeProjectManager::Internal::XMakeWrapper &tool);
        void toolRemoved(const XMakeProjectManager::Internal::XMakeWrapper &tool);

      private:
        XMakeTools();

        std::vector<XMakeWrapperPtr> m_tools;
    };
} // namespace XMakeProjectManager::Internal

#include "XMakeTools.inl"
