#include "ViewLib/View.hpp"
#include "typedefs.h"

DEFINE_CLASS(GorillaUI::Components::View);

extern Logger& getLogger();

namespace GorillaUI::Components
{
    void View::Activate()
    {
        static Vector3 zero = {0.0f, 0.0f, 0.0f};
        auto* didActivate = il2cpp_functions::class_get_method_from_name(il2cpp_utils::ExtractClass (this), "DidActivate", 1);
        if (didActivate)
            il2cpp_utils::RunMethod(this, didActivate, !activatedBefore);
        activatedBefore = true;
    }

    void View::Deactivate()
    {
        auto* didDeactivate = il2cpp_functions::class_get_method_from_name(il2cpp_utils::ExtractClass (this), "DidDeactivate", 0);
        if (didDeactivate)
            il2cpp_utils::RunMethod(this, didDeactivate);
    }
}
