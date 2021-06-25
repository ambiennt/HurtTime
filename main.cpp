#include <dllentry.h>
#include "main.h"

DEFAULT_SETTINGS(settings);

void dllenter() {}
void dllexit() {}
void PreInit() {}
void PostInit() {}

THook(bool, "?hurtEffects@Mob@@UEAA_NAEBVActorDamageSource@@H_N1@Z", void* mob, void* source, int damage, bool knock, bool ignite) {
  bool result = original(mob, source, damage, knock, ignite);
  *(int*)((__int64)mob + 0x270) = settings.hurtTime;
  return result;
}