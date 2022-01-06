#include "Settings.hpp"

#include <XMakeProjectConstant.hpp>

#include <utils/layoutbuilder.h>

namespace XMakeProjectManager::Internal {
    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    Settings::Settings() {
        setSettingsGroup("XMakeProjectManager");
        setAutoApply(false);
    }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    auto Settings::instance() -> Settings * {
        static auto settings = Settings {};

        return &settings;
    }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    GeneralSettingsPage::GeneralSettingsPage() {
        setId(Constants::SettingsPage::GENERAL_ID);
        setDisplayName(tr("General"));
        setDisplayCategory("XMake");
        setCategory(Constants::SettingsPage::CATEGORY);
        setCategoryIconPath(
            Utils::FilePath::fromString(QLatin1String { Constants::Icons::XMAKE_BW }));
        setSettings(Settings::instance());

        setLayouter([](auto *widget) {
            auto &settings = *Settings::instance();

            Utils::Layouting::Column { Utils::Layouting::Stretch {} }.attachTo(widget);
        });
    }

    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    GeneralSettingsPage::~GeneralSettingsPage() = default;
} // namespace XMakeProjectManager::Internal
