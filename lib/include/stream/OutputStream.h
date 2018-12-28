/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once


namespace stm32plus {

  /**
   * @brief Abstract base class for output streams.
   *
   * An output stream gives you the ability to write data sequentially
   * to a device.
   */

  class OutputStream : public StreamBase {

    protected:
      OutputStream& opWrite(void *buffer,uint32_t bufferSize);

    public:
      virtual ~OutputStream() {}

      // some convenience operators when you don't care about errors or endian-ness

      OutputStream& operator<<(int8_t c);
      OutputStream& operator<<(int16_t c);
      OutputStream& operator<<(int32_t c);
      OutputStream& operator<<(uint8_t c);
      OutputStream& operator<<(uint16_t c);
      OutputStream& operator<<(uint32_t c);
      OutputStream& operator<<(const char *string);

      /**
       * Write a byte to the stream.
       * @param[in] c The byte to write.
       * @return false if it fails.
       */

      virtual bool write(uint8_t c)=0;

      /**
       * Write a buffer of data to the stream.
       * @param[in] buffer The buffer of data to write.
       * @param[in] size The number of bytes to write.
       * @return false if the write fails.
       */

      virtual bool write(const void *buffer,uint32_t size)=0;
		
		 /**
 			*	Extended by Seven Robotics. Providing a pure virtual
 			*	write method which returns the number of bytes written 
 			*	to the stream. Required by the Memory stream class.
 			*	Which copies the data pointed to by buffer into its
 			*	local buffer.
 			*	TODO: Provide a timeout mechanism. For non-blocking IO.
 			*/
      virtual size_t write(const void *buffer,size_t size)=0;                                                                                              
			/* Seven Robotics Extension*/

//			virtual size_t read(void* buffer,size_t size)=0;
      /**
       * Flush any cached data to the stream. If the stream does not support
       * caching then it returns true.
       * @return false if it fails.
       */

      virtual bool flush()=0;
  };
}
