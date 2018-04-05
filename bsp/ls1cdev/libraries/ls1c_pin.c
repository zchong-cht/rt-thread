// ���Ź���(��ͨgpio��pwm�����õ�)��ؽӿ�


#include "ls1c_public.h"
#include "ls1c_regs.h"
#include "ls1c_gpio.h"
#include "ls1c_pin.h"


/*
 * ��ָ��pin����Ϊָ����;(��ͨgpio����gpio)
 * @gpio gpio���ű��
 * @purpose ��;
 */
void pin_set_purpose(unsigned int gpio, pin_purpose_t purpose)
{
    volatile unsigned int *gpio_cfgx;           // GPIO_CFGx�Ĵ���
    unsigned int pin = GPIO_GET_PIN(gpio);

    gpio_cfgx = gpio_get_cfg_reg(gpio);
    if (PIN_PURPOSE_GPIO == purpose)            // ����������ͨgpio
    {
        reg_set_one_bit(gpio_cfgx, pin);
    }
    else                                        // ����������������(��gpio)
    {
        reg_clr_one_bit(gpio_cfgx, pin);
    }

    return ;
}



/*
 * ����ָ��pinΪ��n����
 * @gpio gpio���
 * @remap ��n����
 */
void pin_set_remap(unsigned int gpio, pin_remap_t remap)
{
    volatile unsigned int *reg = NULL;          // ���üĴ���
    unsigned int port = GPIO_GET_PORT(gpio);
    unsigned int pin  = GPIO_GET_PIN(gpio);
	int i;

	/*ָ��ȫ��pin����Ϊ0*/
	for(i =0; i <=4; i++)
	{
		reg = (volatile unsigned int *)((LS1C_CBUS_FIRST0)+((port)*0x04)+((i)*0x10));
		// ��0
		reg_clr_one_bit(reg, pin);		
	}		

    switch (port)
    {
        case 0:
            switch (remap)
            {
                case PIN_REMAP_FIRST:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIRST0;
                    break;
                case PIN_REMAP_SECOND:
                    reg = (volatile unsigned int *)LS1C_CBUS_SECOND0;
                    break;
                case PIN_REMAP_THIRD:
                    reg = (volatile unsigned int *)LS1C_CBUS_THIRD0;
                    break;
                case PIN_REMAP_FOURTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FOURTH0;
                    break;
                case PIN_REMAP_FIFTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIFTH0;
                    break;
            }
            break;

        case 1:
            switch (remap)
            {
                case PIN_REMAP_FIRST:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIRST1;
                    break;
                case PIN_REMAP_SECOND:
                    reg = (volatile unsigned int *)LS1C_CBUS_SECOND1;
                    break;
                case PIN_REMAP_THIRD:
                    reg = (volatile unsigned int *)LS1C_CBUS_THIRD1;
                    break;
                case PIN_REMAP_FOURTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FOURTH1;
                    break;
                case PIN_REMAP_FIFTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIFTH1;
                    break;
            }
            break;

        case 2:
            switch (remap)
            {
                case PIN_REMAP_FIRST:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIRST2;
                    break;
                case PIN_REMAP_SECOND:
                    reg = (volatile unsigned int *)LS1C_CBUS_SECOND2;
                    break;
                case PIN_REMAP_THIRD:
                    reg = (volatile unsigned int *)LS1C_CBUS_THIRD2;
                    break;
                case PIN_REMAP_FOURTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FOURTH2;
                    break;
                case PIN_REMAP_FIFTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIFTH2;
                    break;
            }
            break;

        case 3:
            switch (remap)
            {
                case PIN_REMAP_FIRST:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIRST3;
                    break;
                case PIN_REMAP_SECOND:
                    reg = (volatile unsigned int *)LS1C_CBUS_SECOND3;
                    break;
                case PIN_REMAP_THIRD:
                    reg = (volatile unsigned int *)LS1C_CBUS_THIRD3;
                    break;
                case PIN_REMAP_FOURTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FOURTH3;
                    break;
                case PIN_REMAP_FIFTH:
                    reg = (volatile unsigned int *)LS1C_CBUS_FIFTH3;
                    break;
            }
            break;

        default:
            return ;
    }

    // ��1
    reg_set_one_bit(reg, pin);

    return ;
}



