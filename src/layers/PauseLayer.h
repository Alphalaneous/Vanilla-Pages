#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PagePauseLayer, PauseLayer) {

    LATE_MODIFY(PauseLayer::customSetup);

    void customSetup(){
        PauseLayer::customSetup();

        if(Mod::get()->getSettingValue<bool>("pause-layer-menu")){
            auto centerMenu = getChildByID("center-button-menu");
            centerMenu->ignoreAnchorPointForPosition(false);
            centerMenu->setContentSize({450, 85});

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
            }

            PageMenu* menuPage = PageMenu::create(typeinfo_cast<CCMenu*>(centerMenu), layout, 6);
            menuPage->scaleWhenFull();
            addChild(menuPage);
        }
    }
};