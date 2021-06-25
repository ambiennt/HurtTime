#pragma once

#include <yaml.h>
#include <base/log.h>
#include <hook.h>
#include <base/base.h>

inline struct Settings {

    int hurtTime = 10;

    template <typename IO> static inline bool io(IO f, Settings &settings, YAML::Node &node) {
        return f(settings.hurtTime, node["hurtTime"]);
    }
}
settings;

DEF_LOGGER("hurtTime");