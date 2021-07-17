#pragma once

#include <map>

#include "custom-types/shared/macros.hpp"
#include "../EKeyboardKey.hpp"

#include "../ViewLib/CustomScreenInfo.hpp"
#include "../ViewLib/GorillaKeyboardButton.hpp"
#include "../ViewLib/ViewManager.hpp"
#include "../ViewLib/View.hpp"

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Color.hpp"
#include "UnityEngine/Texture2D.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
#include "GlobalNamespace/GorillaComputer.hpp"

namespace GorillaUI::Components {
    class GorillaKeyboardButton;
    class ViewManager;
    class View;
}

using keymap = std::map<GorillaUI::EKeyboardKey, GorillaUI::Components::GorillaKeyboardButton*>;

DECLARE_CLASS_CODEGEN(GorillaUI, CustomComputer, UnityEngine::MonoBehaviour,
    DECLARE_INSTANCE_METHOD(void, ReplaceKeys);
    DECLARE_STATIC_METHOD(void, Redraw);
    DECLARE_INSTANCE_METHOD(void, SetBG, float r, float g, float b);
    DECLARE_INSTANCE_METHOD(void, SetBGTex, UnityEngine::Texture2D* tex);
    DECLARE_INSTANCE_FIELD(bool, initialized);
    DECLARE_INSTANCE_FIELD(GlobalNamespace::GorillaComputer*, gorillaComputer);

    private:
        GorillaUI::Components::GorillaKeyboardButton* CreateKeyNoInit(UnityEngine::GameObject* prefab, std::string goName, UnityEngine::Vector3 offset, EKeyboardKey key);
        GorillaUI::Components::GorillaKeyboardButton* CreateKey(UnityEngine::GameObject* prefab, std::string goName, UnityEngine::Vector3 offset, EKeyboardKey key);
        GorillaUI::Components::GorillaKeyboardButton* CreateKey(UnityEngine::GameObject* prefab, std::string goName, UnityEngine::Vector3 offset, EKeyboardKey key, std::string label);
        GorillaUI::Components::GorillaKeyboardButton* CreateKey(UnityEngine::GameObject* prefab, std::string goName, UnityEngine::Vector3 offset, EKeyboardKey key, std::string label, UnityEngine::Color color);
        CustomScreenInfo CreateMonitor();

        keymap keys;
        CustomScreenInfo screenInfo;
        static inline GorillaUI::CustomComputer* instance = nullptr;
    public:
        GorillaUI::Components::ViewManager* activeViewManager = nullptr;
        void Init(GorillaUI::Components::View* initialView);
        void PressButton(GorillaUI::Components::GorillaKeyboardButton* button);

        static CustomComputer* get_instance();
)