#include "AnyMiss.hpp"
#include "AnyMissConfig.hpp"

void DidActivate(HMUI::ViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    using namespace UnityEngine;

    if (firstActivation) {
        GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(self->get_transform());

        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Miss Text", getAnyMissConfig().HideMissText.GetValue(), 
            [](bool value) {
                getAnyMissConfig().HideMissText.SetValue(value);
            }
        );
        
        QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide FC Break Lines Animation", getAnyMissConfig().HideFCBreakLinesAnimation.GetValue(), 
            [](bool value) {
                getAnyMissConfig().HideFCBreakLinesAnimation.SetValue(value);
            }
        );
    }
}

void AnyMiss::Install() {
    QuestUI::Init();
    QuestUI::Register::RegisterModSettingsViewController(modInfo, DidActivate);

    AnyMiss::Hooks::ComboUIController();
    AnyMiss::Hooks::FlyingSpriteSpawner();
}
