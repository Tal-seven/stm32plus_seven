#pragma once
namespace stm32plus {

template<bool enable>
class TimerCCARRPreloadFeature : public TimerFeatureBase {
    public:
     TimerCCARRPreloadFeature(Timer& timer);
};

template<bool enable>
inline TimerCCARRPreloadFeature<enable>::TimerCCARRPreloadFeature(Timer& timer) : TimerFeatureBase(timer) {
    if(enable) {
        TIM_CCPreloadControl(_timer,ENABLE);
        TIM_ARRPreloadConfig(_timer,ENABLE);
    }
    else {
        TIM_CCPreloadControl(_timer,DISABLE);
        TIM_ARRPreloadConfig(_timer,DISABLE);
    }
} 

}