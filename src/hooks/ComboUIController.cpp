#include "AnyMiss.hpp"
#include "AnyMissConfig.hpp"

#include "GlobalNamespace/ComboUIController.hpp"

MAKE_HOOK_MATCH(
    ComboUIController_HandleComboBreakingEventHappened,
    &GlobalNamespace::ComboUIController::HandleComboBreakingEventHappened,
    void,
    GlobalNamespace::ComboUIController* self
) {
    if (getAnyMissConfig().HideFCBreakLinesAnimation.GetValue()) {
        if (!self->comboLost) {
            self->comboLost = true;
            self->get_transform()->Find(il2cpp_utils::newcsstr("Line0"))->get_gameObject()->SetActive(false);
            self->get_transform()->Find(il2cpp_utils::newcsstr("Line1"))->get_gameObject()->SetActive(false);
        }
    } else {
        ComboUIController_HandleComboBreakingEventHappened(self);
    }
}

void AnyMiss::Hooks::ComboUIController() {
    INSTALL_HOOK(getLogger(), ComboUIController_HandleComboBreakingEventHappened);
}