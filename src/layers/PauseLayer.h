#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PagePauseLayer, PauseLayer) {

    LATE_MODIFY(PauseLayer::customSetup);

    void modifyMenu(CCNode* menu) {
        if (CCBool* dontModify = typeinfo_cast<CCBool*>(menu->getUserObject("dont-modify"_spr))){
            if (dontModify->getValue()) {
                return;
            }
        }
        menu->ignoreAnchorPointForPosition(false);
        menu->setContentSize({450, 85});
    }

    void customSetup(){
        PauseLayer::customSetup();

        if (Mod::get()->getSettingValue<bool>("pause-layer-right-menu")) {
            if (auto rightMenu = getChildByID("right-button-menu")) {
                rightMenu->setContentHeight(140);
                int childrenCount = rightMenu->getChildrenCount();
                if (childrenCount > 4) {
                    rightMenu->setPositionY(rightMenu->getPositionY() - 20);
                }
                PageMenu* pageMenu = static_cast<PageMenu*>(rightMenu);
                pageMenu->setPaged(4, PageOrientation::VERTICAL, 195);
                pageMenu->setFixed(30);
                pageMenu->setButtonScale(0.5f);

                if (AxisLayout* layout = typeinfo_cast<AxisLayout*>(rightMenu->getLayout())) {
                    layout->setAxisAlignment(AxisAlignment::Center);
                }
                rightMenu->updateLayout();
            }
        }
        if (Mod::get()->getSettingValue<bool>("pause-layer-menu")) {
            if (auto centerMenu = getChildByID("center-button-menu")) {
                modifyMenu(centerMenu);

                int childrenCount = centerMenu->getChildrenCount();

                Layout* layout;

                if (centerMenu->getLayout()) {
                    layout = centerMenu->getLayout();
                }
                else {
                    layout = RowLayout::create();
                    RowLayout* rLayout = static_cast<RowLayout*>(layout);
                    rLayout->setGrowCrossAxis(true);
                    rLayout->setCrossAxisOverflow(false);
                    rLayout->setAxisAlignment(AxisAlignment::Center);
                    rLayout->setCrossAxisAlignment(AxisAlignment::Center);
                    rLayout->setCrossAxisLineAlignment(AxisAlignment::Center);
                    rLayout->setGap(10);
                    rLayout->ignoreInvisibleChildren(true);
                    centerMenu->setLayout(rLayout);
                }
                static_cast<PageMenu*>(centerMenu)->setPaged(6, PageOrientation::HORIZONTAL, 450);
            }
        }
    }
};