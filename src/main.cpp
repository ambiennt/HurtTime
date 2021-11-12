#include <dllentry.h>
#include <hook.h>
#include <base/base.h>
#include <base/log.h>
#include <yaml.h>
#include <Actor/Mob.h>

DEF_LOGGER("HurtTime");

void dllenter() {}
void dllexit() {}

inline struct Settings {

    int hurtTime = 10;

    template <typename IO> static inline bool io(IO f, Settings &settings, YAML::Node &node) {
        return f(settings.hurtTime, node["hurtTime"]);
    }
} settings;

DEFAULT_SETTINGS(settings);

THook(bool, "?hurtEffects@Mob@@UEAA_NAEBVActorDamageSource@@H_N1@Z",
    Mob *mob, const ActorDamageSource *source, int damage, bool knock, bool ignite) {
    bool result = original(mob, source, damage, knock, ignite);
    mob->mInvulnerableTime = settings.hurtTime;
    return result;
}