/* 
 Copyright (C) 2019 hidenorly

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef __PAL_SENSOR_SH200Q_H__
#define __PAL_SENSOR_SH200Q_H__

#include <bsp.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


int SH200Q_Init(void);
void SH200Q_getGyroData(float* gyroX, float* gyroY, float* gyroZ);
void SH200Q_getAccelData(float* accelX, float* accelY, float* accelZ);
void SH200Q_getAhrsData(float* pitch, float* roll, float* yaw);

// board config
#define SH200Q_I2C_BUS		I2C_DEVICE_0    // iic0
#define SH200Q_I2C_PIN_SCL	28
#define SH200Q_I2C_PIN_SDA	29
#define SH200Q_I2C_SLA		0x6C

#ifdef SH200Q_IMPL
static float g_accelK = 8.0f/32768.0f;
static float g_gyroK = 2000.0f/32768.0f;
int SH200Q_i2c_send_data(uint8_t cmd, size_t send_buf_len, const uint8_t *send_buf);
int SH200Q_i2c_send_byte(uint8_t cmd, const uint8_t sendData);

int SH200Q_i2c_recv_data(uint8_t cmd, size_t receive_buf_len, uint8_t *receive_buf);
uint8_t SH200Q_i2c_recv_byte(uint8_t cmd);

#define BIT0	(0x01)
#define BIT1	(0x01<<1)
#define BIT2	(0x01<<2)
#define BIT3	(0x01<<3)
#define BIT4	(0x01<<4)
#define BIT5	(0x01<<5)
#define BIT6	(0x01<<6)
#define BIT7	(0x01<<7)

#define SH200Q_WHOAMI            0x30
#define SH200Q_WHOAMI_VALUE		 0x18

#define SH200Q_PWR_MGMT_1        0x6B
#define SH200Q_PWR_MGMT_1_RESET  BIT7
#define SH200Q_PWR_MGMT_2        0x6C

#define SH200Q_ACCEL_CONFIG      0x1C
#define SH200Q_ACCEL_CONFIG_2G   (0)
#define SH200Q_ACCEL_CONFIG_4G   (BIT3)
#define SH200Q_ACCEL_CONFIG_8G   (BIT4)
#define SH200Q_ACCEL_CONFIG_16G  (BIT3 | BIT4)
#define SH200Q_ACCEL_CONFIG2     0x1D
#define SH200Q_ACCEL_XOUT_H      0x3B

#define SH200Q_GYRO_CONFIG       0x1B
#define SH200Q_GYRO_CONFIG_250DPS		(0)
#define SH200Q_GYRO_CONFIG_500DPS		(BIT3)
#define SH200Q_GYRO_CONFIG_10000DPS	(BIT4)
#define SH200Q_GYRO_CONFIG_2000DPSG	(BIT3 | BIT4)
#define SH200Q_GYRO_XOUT_H       0x43

#define SH200Q_CONFIG            0x1A
#define SH200Q_SMPLRT_DIV        0x19
#define SH200Q_INT_ENABLE        0x38
#define SH200Q_INT_ENABLE_VAL    0x01
#define SH200Q_USER_CTRL         0x6A
#define SH200Q_FIFO_EN           0x23
#define SH200Q_INT_PIN_CFG       0x37
#define SH200Q_INT_PIN_CFG_VAL	  0x20

#define SH200Q_TEMP_OUT_H        0x41
#define SH200Q_TEMP_OUT_L        0x42
#endif // SH200Q_IMPL

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __PAL_SENSOR_SH200Q_H__
