#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PageMenuLayer, MenuLayer) {

    LATE_MODIFY(MenuLayer::init);

    bool init(){
        if (!MenuLayer::init()) {
            return false;
        }

        if (Mod::get()->getSettingValue<bool>("menulayer-bottom-menu")) {
            if (auto bottomMenu = getChildByID("bottom-menu")) {
                static_cast<PageMenu*>(bottomMenu)->setPaged(6, PageOrientation::HORIZONTAL, 284);
            }
        }

        if (Mod::get()->getSettingValue<bool>("menulayer-right-menu")) {
            if (auto rightMenu = getChildByID("right-side-menu")) {
                static_cast<PageMenu*>(rightMenu)->setPaged(3, PageOrientation::VERTICAL, 180, -12);
            }
        }

        return true;
    }
};