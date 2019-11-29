/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */


#pragma once


// ensure the MCU series is correct
#if !defined(STM32PLUS_F1) && !defined(STM32PLUS_F1_CL_E)
#error This class can only be used with the STM32F1 series
#endif


namespace stm32plus {


  /**
   * Default pin package:
   * (TX,RX) = (PA12,PA11)
   */

  struct Can2DefaultPinPackage {
    enum{
      Port_TX=GPIOB_BASE,
      Port_RX=GPIOB_BASE,

      Pin_TX=GPIO_Pin_13,
      Pin_RX=GPIO_Pin_12 
    };
  };


  /**
   * The default, non-remapped pin package
   */

  template<class... Features>
  struct Can2 : CanPeripheral<Can2DefaultPinPackage,PERIPHERAL_CAN2>,
  	  	  	  	  Features... {
    /**
     * Constructor
     * @param params Initialisation parameters
     */

	  Can2(const Parameters& params)
	    : CanPeripheral<Can2DefaultPinPackage,PERIPHERAL_CAN2>(params),
	      Features(static_cast<Can&>(*this))... {

	    initialisePeripheral();
      RecursiveVoidInit<Can2,Features...>::tinit(this);
	  }
  };
}
