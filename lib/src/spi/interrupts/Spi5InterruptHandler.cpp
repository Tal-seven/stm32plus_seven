/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#include "config/stm32plus.h"

#if !defined(STM32PLUS_F1_MD_VL) && !defined(STM32PLUS_F0)

#include "config/spi.h"
#include "config/i2s.h"


using namespace stm32plus;


// static initialisers for the hack that forces the IRQ handlers to be linked

template<> SpiInterruptFeatureEnabler<5>::FPTR SpiInterruptFeatureEnabler<5>::_forceLinkage=nullptr;


extern "C" {

#if defined(USE_SPI4_INTERRUPT) 

  void __attribute__ ((interrupt("IRQ"))) SPI5_IRQHandler(void) {
    if(SPI_I2S_GetITStatus(SPI5,SPI_I2S_IT_RXNE)!=RESET) {
      SpiInterruptFeature<5>::_spiInstance->SpiInterruptEventSender.raiseEvent(SpiEventType::EVENT_RECEIVE);
      SPI_I2S_ClearITPendingBit(SPI5,SPI_I2S_IT_RXNE);
    }
    else if(SPI_I2S_GetITStatus(SPI5,SPI_I2S_IT_TXE)!=RESET) {
      SpiInterruptFeature<5>::_spiInstance->SpiInterruptEventSender.raiseEvent(SpiEventType::EVENT_READY_TO_TRANSMIT);
      SPI_I2S_ClearITPendingBit(SPI5,SPI_I2S_IT_TXE);
    }
    __DSB();      // prevent erroneous recall of this handler due to delayed memory write
  }

#endif
} // extern "C"

#endif
