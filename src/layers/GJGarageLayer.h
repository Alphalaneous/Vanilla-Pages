
#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <alphalaneous.pages_api/include/PageMenu.h>
#include "../Macros.h"

using namespace geode::prelude;

class $modify(PageGJGarageLayer, GJGarageLayer) {

    LATE_MODIFY(GJGarageLayer::init);

    bool init() {
        if (!GJGarageLayer::init()) return false;

        if (Mod::get()->getSettingValue<bool>("garage-left-menu")) {
            if (auto leftMenu = getChildByID("shards-menu")) {
                leftMenu->setContentHeight(160);
                int childrenCount = leftMenu->getChildrenCount();
                if (childrenCount > 5) {
                    leftMenu->setPositionY(leftMenu->getPositionY() + 25);
                    leftMenu->setPositionX(leftMenu->getPositionX() - 5);

                }
                PageMenu* pageMenu = static_cast<PageMenu*>(leftMenu);
                pageMenu->setPaged(5, PageOrientation::VERTICAL, 200);
                pageMenu->setFixed(30);
                pageMenu->setButtonScale(0.5f);

                if (AxisLayout* layout = typeinfo_cast<AxisLayout*>(leftMenu->getLayout())) {
                    layout->setAxisAlignment(AxisAlignment::Center);
                }
                leftMenu->updateLayout();
            }
        }

        return true;
    }

};