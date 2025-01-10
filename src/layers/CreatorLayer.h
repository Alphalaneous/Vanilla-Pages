#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PageCreatorLayer, CreatorLayer) {

    LATE_MODIFY(CreatorLayer::init);

    bool init(){
        if (!CreatorLayer::init()) {
            return false;
        }

        if (Mod::get()->getSettingValue<bool>("creator-layer-menu")) {
            if (auto creatorButtonsMenu = getChildByID("creator-buttons-menu")) {
                CCSize winSize = CCDirector::get()->getWinSize();
                static_cast<PageMenu*>(creatorButtonsMenu)->setPaged(15, PageOrientation::HORIZONTAL, winSize.width - 10);
            }
        }

        return true;
    }
};
