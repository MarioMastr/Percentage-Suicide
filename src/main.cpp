
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>

class $modify(PlayLayer) {
    void postUpdate(float p0) {
        PlayLayer::postUpdate(p0);

        int percentage     = Mod::get()->getSettingValue<int64_t>("percentage");
        bool straightUpDie = Mod::get()->getSettingValue<bool>("straightUpDie");

        if (getCurrentPercentInt() == percentage) {
            if (straightUpDie)
                PlayLayer::destroyPlayer(m_player1, nullptr);
            else
                PlayLayer::resetLevelFromStart();
        }
    }
};