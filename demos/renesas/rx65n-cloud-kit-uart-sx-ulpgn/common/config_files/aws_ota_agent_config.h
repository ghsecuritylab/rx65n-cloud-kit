/*
 * Amazon FreeRTOS V0.9.5
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/**
 * @file aws_ota_agent_config.h
 * @brief OTA user configurable settings.
 */

#ifndef _AWS_OTA_AGENT_CONFIG_H_
#define _AWS_OTA_AGENT_CONFIG_H_

/**
 * @brief Special OTA Agent printing definition (in stead of definition in lib/include/aws_ota_agent.h).
 */
#define OTA_DEBUG_LOG_LEVEL                     1

/**
 * @brief The number of words allocated to the stack for the OTA agent.
 */
#define otaconfigSTACK_SIZE                     3584U

/**
 * @brief Log base 2 of the size of the file data block message (excluding the header).
 *
 * 10 bits yields a data block size of 1KB.
 */
#define otaconfigLOG2_FILE_BLOCK_SIZE           10UL

/**
 * @brief Milliseconds to wait for the self test phase to succeed before we force reset.
 */
#define otaconfigSELF_TEST_RESPONSE_WAIT_MS     16000U

/**
 * @brief Milliseconds to wait before requesting data blocks from the OTA service if nothing is happening.
 *
 * The wait timer is reset whenever a data block is received from the OTA service so we will only send
 * the request message after being idle for this amount of time.
 */
#define otaconfigFILE_REQUEST_WAIT_MS           2500U

/**
 * @brief The OTA agent task priority. Normally it runs at a low priority.
 */
#define otaconfigAGENT_PRIORITY                 tskIDLE_PRIORITY

/**
 * @brief The maximum allowed length of the thing name used by the OTA agent.
 *
 * AWS IoT requires Thing names to be unique for each device that connects to the broker.
 * Likewise, the OTA agent requires the developer to construct and pass in the Thing name when
 * initializing the OTA agent. The agent uses this size to allocate static storage for the
 * Thing name used in all OTA base topics. Namely $aws/things/<thingName>
 */
#define otaconfigMAX_THINGNAME_LEN              64U

/**
 * @brief Special OTA Agent printing macros (in stead of definitions in lib/include/aws_ota_agent.h).
 */
#if OTA_DEBUG_LOG_LEVEL >= 1
#define DEFINE_OTA_METHOD_NAME(name) static const char OTA_METHOD_NAME[] = name;
#define OTA_LOG_L1 vLoggingPrintf
#else
#define DEFINE_OTA_METHOD_NAME(name)
#if !(defined(__CCRX__) && defined(__cplusplus))
#define OTA_LOG_L1(...)
#else
/* CC-RX' C++ mode does not support variadic macros */
#define OTA_LOG_L1(x)   /* More than two arguments are not available. */
#endif
#endif
#if OTA_DEBUG_LOG_LEVEL >= 2
#define DEFINE_OTA_METHOD_NAME_L2(name) static const char OTA_METHOD_NAME[] = name;
#define OTA_LOG_L2 vLoggingPrintf
#else
#define DEFINE_OTA_METHOD_NAME_L2(name)
#if !(defined(__CCRX__) && defined(__cplusplus))
#define OTA_LOG_L2(...)
#else
/* CC-RX' C++ mode does not support variadic macros */
#define OTA_LOG_L2(x)   /* More than two arguments are not available. */
#endif
#endif
#if OTA_DEBUG_LOG_LEVEL >= 3
#define DEFINE_OTA_METHOD_NAME_L3(name) static const char OTA_METHOD_NAME[] = name;
#define OTA_LOG_L3 vLoggingPrintf
#else
#define DEFINE_OTA_METHOD_NAME_L3(name)
#if !(defined(__CCRX__) && defined(__cplusplus))
#define OTA_LOG_L3(...)
#else
/* CC-RX' C++ mode does not support variadic macros */
#define OTA_LOG_L3(x)   /* More than two arguments are not available. */
#endif
#endif

#endif /* _AWS_OTA_AGENT_CONFIG_H_ */
