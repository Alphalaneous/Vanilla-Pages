#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PageEditorUI, EditorUI) {

    LATE_MODIFY(EditorUI::init);

    bool init(LevelEditorLayer* editorLayer){
        if (!EditorUI::init(editorLayer)) {
            return false;
        }

        if(Mod::get()->getSettingValue<bool>("editor-build-tabs-menu")){
            createPageForTabs("build-tabs-menu");
            createPageForTabs("edit-tabs-menu");
            createPageForTabs("delete-tabs-menu");
        }

        return true;
    }

    void createPageForTabs(std::string id) {
        if (auto tabsMenu = getChildByID(id.c_str())) {
            if (auto toolbarTogglesMenu = getChildByID("toolbar-toggles-menu")) {
                tabsMenu->setPositionY(toolbarTogglesMenu->getScaledContentSize().height);
                tabsMenu->setAnchorPoint({0.5, 0});
                CCSize winSize = CCDirector::get()->getWinSize();

                float scale = tabsMenu->getScale();

                float newWidth = 520 / scale;

                tabsMenu->setContentSize({newWidth, 17.5});

                PageMenu* pageMenu = static_cast<PageMenu*>(tabsMenu);

                pageMenu->setPaged(std::ceil(16 / scale), PageOrientation::HORIZONTAL, winSize.width);
                pageMenu->setButtonScale(0.5f);
            }
        }
    }
};
