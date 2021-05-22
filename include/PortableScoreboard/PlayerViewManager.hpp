#pragma once

#include "EKeyboardKey.hpp"
#include "custom-types/shared/macros.hpp"
#include "ViewLib/ViewManager.hpp"
#include "ViewLib/View.hpp"
#include "PortableScoreboard/PlayerDisplayInfo.hpp"

DECLARE_CLASS_CODEGEN(GorillaUI, PlayerViewManager, GorillaUI::Components::ViewManager, 
    DECLARE_METHOD(void, DidActivate, bool firstActivation);
    DECLARE_METHOD(void, NotifyOfKeyPress, int key);
    DECLARE_METHOD(void, BackButtonWasPressed, GorillaUI::Components::View* view);
    DECLARE_INSTANCE_FIELD(Components::View*, playerView);
    public:
        PlayerDisplayInfo playerInfo;

    REGISTER_FUNCTION(
        REGISTER_METHOD(DidActivate);
        REGISTER_METHOD(NotifyOfKeyPress);
        REGISTER_METHOD(BackButtonWasPressed);
        REGISTER_FIELD(playerView);
    )
)