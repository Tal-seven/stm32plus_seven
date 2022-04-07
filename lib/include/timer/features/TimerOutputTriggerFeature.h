/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once


namespace stm32plus {


 

  template<uint16_t TOutputSource>
  class TimerOutputTriggerFeature : public TimerFeatureBase {
    public:
      TimerOutputTriggerFeature(Timer& timer);
      void enableOutputTrigger() const;
      //Seven Robotics edit, allow multiple trigger features in one class 
      // be accessible from the enclosing class type.
      void enableEnableTrigger() const;
      void enableUpdateTrigger() const;
  };

  

  template<uint16_t TOutputSource>
  inline TimerOutputTriggerFeature<TOutputSource>::TimerOutputTriggerFeature(Timer& timer)
    : TimerFeatureBase(timer) {
  }


  /**
   * The master feature cannot be enabled until the rest of the timer is set up
   * so this cannot be done in the constructor
   */

  template<uint16_t TOutputSource>
  inline void TimerOutputTriggerFeature<TOutputSource>::enableOutputTrigger() const {

    // select the output source and enable master mode
    TIM_SelectOutputTrigger(_timer,TOutputSource);
  }
  
  template<uint16_t TOutputSource>
  inline void TimerOutputTriggerFeature<TOutputSource>::enableEnableTrigger() const {}

   template<uint16_t TOutputSource>
  inline void TimerOutputTriggerFeature<TOutputSource>::enableUpdateTrigger() const {}

  template<>
  inline void TimerOutputTriggerFeature<TIM_TRGOSource_Enable>::enableEnableTrigger() const {
      TIM_SelectOutputTrigger(_timer,TIM_TRGOSource_Reset);
  }

  template<>
  inline void TimerOutputTriggerFeature<TIM_TRGOSource_Update>::enableUpdateTrigger() const {
      TIM_SelectOutputTrigger(_timer,TIM_TRGOSource_Update);
  }

  /**
   * Typedefs for easy access
   */

  typedef TimerOutputTriggerFeature<TIM_TRGOSource_Reset> TimerResetTriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_Enable> TimerEnableTriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_Update> TimerUpdateTriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_OC1> TimerCompareTriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_OC1Ref> TimerOutputCompare1TriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_OC2Ref> TimerOutputCompare2TriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_OC3Ref> TimerOutputCompare3TriggerFeature;
  typedef TimerOutputTriggerFeature<TIM_TRGOSource_OC4Ref> TimerOutputCompare4TriggerFeature;
}
