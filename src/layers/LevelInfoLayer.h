#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PageLevelInfoLayer, LevelInfoLayer) {

    LATE_MODIFY(LevelInfoLayer::init);

    struct Fields {
        PageMenu* m_leftSidePage;
    };

    bool init(GJGameLevel* level, bool challenge){
        if (!LevelInfoLayer::init(level, challenge)) {
            return false;
        }

        if (Mod::get()->getSettingValue<bool>("levelinfolayer-left-menu")){
            if (auto leftSideMenu = getChildByID("left-side-menu")) {
                leftSideMenu->setPosition({leftSideMenu->getPosition().x, leftSideMenu->getPosition().y + 20});
                static_cast<PageMenu*>(leftSideMenu)->setPaged(3, PageOrientation::VERTICAL, 150);
            }
        }

        return true;
    }
};