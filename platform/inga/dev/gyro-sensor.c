/* GYROSCOPE sensor interface 
 * Author  : Georg von Zengen
 * Created : 2011/10/17
 */
#include "contiki.h"
#include "lib/sensors.h"
#include "interfaces/gyro-l3g4200d.h"
#include "dev/gyro-sensor.h"
const struct sensors_sensor gyro_sensor;
uint8_t gyro_state=0;
/*---------------------------------------------------------------------------*/
static int
value(int type)
{
  switch(type) {
  case X_AS:
    return l3g4200d_get_x_angle();

  case Y_AS:
    return l3g4200d_get_z_angle();

  case Z_AS:
    return l3g4200d_get_y_angle();

  case TEMP_AS: //only for relative temperature measurements 
		return (int16_t) l3g4200d_get_temp();
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
static int
status(int type)
{
  return gyro_state;
}
/*---------------------------------------------------------------------------*/
static int
configure(int type, int c)
{
  gyro_state=1;
  return l3g4200d_init();
}
/*---------------------------------------------------------------------------*/
SENSORS_SENSOR(gyro_sensor, "GYROSCOPE", value, configure, status);