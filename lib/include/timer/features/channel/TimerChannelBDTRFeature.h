

#pragma once


namespace stm32plus {

  /**
   * Feature class to set the OC polarity
   */

  template<uint16_t OSSRState,uint16_t OSSIState,uint16_t Deadtime,bool Break=false>
  struct TimerChannelBDTRFeature {

    /**
     * Constructor, set the flag in the OC struct
     */

    TimerChannelBDTRFeature(TimerChannelFeatureBase& tcfb) {

      TIM_BDTRInitTypeDef& bdtr=static_cast<TIM_BDTRInitTypeDef&>(tcfb);
      bdtr.TIM_OSSRState = OSSRState;
      bdtr.TIM_OSSIState = OSSIState;
      bdtr.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
      bdtr.TIM_DeadTime = Deadtime;
      bdtr.TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;
      bdtr.TIM_Break = Break?TIM_Break_Enable:TIM_Break_Disable;
      bdtr.TIM_BreakPolarity = Break?TIM_BreakPolarity_Low:TIM_BreakPolarity_High;
         
      TIM_BDTRConfig(static_cast<TIM_TypeDef*>(static_cast<Timer&>(tcfb)),&bdtr);
    }
  };

}