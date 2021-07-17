#pragma once

#include "EKeyboardKey.hpp"
#include "custom-types/shared/macros.hpp"
#include "ViewLib/ViewManager.hpp"
#include "ViewLib/View.hpp"
#include "PortableScoreboard/PlayerDisplayInfo.hpp"

DECLARE_CLASS_CUSTOM(GorillaUI, PlayerViewManager, GorillaUI::Components::ViewManager, 
    DECLARE_INSTANCE_METHOD(void, DidActivate, bool firstActivation);
    DECLARE_INSTANCE_METHOD(void, NotifyOfKeyPress, int key);
    DECLARE_INSTANCE_METHOD(void, BackButtonWasPressed, GorillaUI::Components::View* view);
    DECLARE_INSTANCE_FIELD(Components::View*, playerView);
    public:
        PlayerDisplayInfo playerInfo;
)