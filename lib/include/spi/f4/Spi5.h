/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once

// ensure the MCU series is correct
#ifndef STM32F429_439xx
#error This class can only be used with the STM32F4 series
#endif


namespace stm32plus {

  /**
   * Generic class for any pin package
   */

  template<class TPinPackage,class... Features>
  struct Spi5_Custom : SpiPeripheral<TPinPackage,PERIPHERAL_SPI5>,
                       Features... {

    Spi5_Custom(const typename SpiPeripheral<TPinPackage,PERIPHERAL_SPI5>::Parameters& params)
      : SpiPeripheral<TPinPackage,PERIPHERAL_SPI5>(params),
        Features(static_cast<Spi&>(*this))... {
    }
  };


  /*
   * Default pin package:
   */

  struct Spi5DefaultPinPackage {
    enum {
      Port_NSS =GPIOF_BASE,
      Port_SCK =GPIOF_BASE,
      Port_MISO=GPIOF_BASE,
      Port_MOSI=GPIOF_BASE,

      Pin_NSS  = GPIO_Pin_6,
      Pin_SCK  = GPIO_Pin_7,
      Pin_MISO = GPIO_Pin_8,
      Pin_MOSI = GPIO_Pin_9
    };
  };


  /**
   * Convenience class to match the F1 pin for pin.
   */

  template<class... Features>
  struct Spi5 : SpiPeripheral<Spi5DefaultPinPackage,PERIPHERAL_SPI5>,
                Features... {

    Spi5(const Parameters& params)
      : SpiPeripheral<Spi5DefaultPinPackage,PERIPHERAL_SPI5>(params),
        Features(static_cast<Spi&>(*this))... {
    }
  };


  /**
   * NSS is on PA[15]. The others move to PB
   */

  struct Spi5Remap1PinPackage {
    enum {
      Port_NSS=GPIOH_BASE,
      Port_SCK=GPIOH_BASE,
      Port_MISO=GPIOH_BASE,
      Port_MOSI=GPIOF_BASE,

      Pin_NSS  = GPIO_Pin_5,
      Pin_SCK  = GPIO_Pin_6,
      Pin_MISO = GPIO_Pin_7,
      Pin_MOSI = GPIO_Pin_11
    };
  };


  /**
   * Convenience class to match the F1 pin for pin.
   */

  template<class... Features>
  struct Spi5_Remap1 : SpiPeripheral<Spi5Remap1PinPackage,PERIPHERAL_SPI5>,
                       Features... {

    Spi5_Remap1(const Parameters& params)
      : SpiPeripheral<Spi5Remap1PinPackage,PERIPHERAL_SPI5>(params),
        Features(static_cast<Spi&>(*this))... {
    }
  };
}

