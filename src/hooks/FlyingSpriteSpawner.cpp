#include "AnyMiss.hpp"
#include "AnyMissConfig.hpp"

#include "GlobalNamespace/FlyingSpriteSpawner.hpp"

MAKE_HOOK_MATCH(
    FlyingSpriteSpawner_SpawnFlyingSprite,
    &GlobalNamespace::FlyingSpriteSpawner::SpawnFlyingSprite,
    void,
    GlobalNamespace::FlyingSpriteSpawner* self,
    UnityEngine::Vector3 pos,
    UnityEngine::Quaternion rotation,
    UnityEngine::Quaternion inverseRotation
) {
    if (!getAnyMissConfig().HideMissText.GetValue()) {
        FlyingSpriteSpawner_SpawnFlyingSprite(self, pos, rotation, inverseRotation);
    }
}

void AnyMiss::Hooks::FlyingSpriteSpawner() {
    INSTALL_HOOK(getLogger(), FlyingSpriteSpawner_SpawnFlyingSprite);
}