/*    


Battery.c file
��д�ߣ�С��  (Camel)
����E-mail��375836945@qq.com
���뻷����MDK-Lite  Version: 4.23
����ʱ��: 2014-01-28
���ܣ�
1.��ؼ��AD��ʼ��
2.����ѹ����ã��ṩƬ���¶ȴ���������
------------------------------------
*/

#include "Battery.h"
#include "config.h"
//#include "UART1.h"
//#include "stdio.h"
//#include "CommApp.h"
//#include "ReceiveData.h"

//ʵ����һ����ѹ��Ϣ�ṹ��
Bat_Typedef Battery;


////��ʼ����ؼ��ADC
////����ADC1��ͨ��8	
////BatteryCheck---->PB0
//void BatteryCheckInit()
//{
//  
// //�ȳ�PB0Ϊģ������
//  RCC->APB2ENR|=1<<3;    //ʹ��PORTB��ʱ�� 
//  GPIOB->CRL&=0XFFFFFFF0;//PB0	anolog����
//	//ͨ��8	 
//	RCC->APB2ENR|=1<<9;    //ADC1ʱ��ʹ��	  
//	RCC->APB2RSTR|=1<<9;   //ADC1��λ
//	RCC->APB2RSTR&=~(1<<9);//��λ����	    
//	RCC->CFGR&=~(3<<14);   //��Ƶ��������	
//	//SYSCLK/DIV2=12M ADCʱ������Ϊ12M,ADC���ʱ�Ӳ��ܳ���14M!
//	//���򽫵���ADC׼ȷ���½�! 
//	RCC->CFGR|=2<<14;      	 
//	ADC1->CR1&=0XF0FFFF;   //����ģʽ����
//	ADC1->CR1|=0<<16;      //��������ģʽ  
//	ADC1->CR1&=~(1<<8);    //��ɨ��ģʽ	  
//	ADC1->CR2&=~(1<<1);    //����ת��ģʽ
//	ADC1->CR2&=~(7<<17);	   
//	ADC1->CR2|=7<<17;	     //��������ת��  
//	ADC1->CR2|=1<<20;      //ʹ�����ⲿ����(SWSTART)!!!	����ʹ��һ���¼�������
//	ADC1->CR2&=~(1<<11);   //�Ҷ���	 
//	ADC1->CR2|=1<<23;      //ʹ���¶ȴ�����

//	ADC1->SQR1&=~(0XF<<20);
//	ADC1->SQR1&=0<<20;     //1��ת���ڹ��������� Ҳ����ֻת����������1 			   
//	//����ͨ��1�Ĳ���ʱ��
//	ADC1->SMPR2&=~(7<<3);  //ͨ��1����ʱ�����	  
// 	ADC1->SMPR2|=7<<3;     //ͨ��1  239.5����,��߲���ʱ�������߾�ȷ��	 

// 	ADC1->SMPR1&=~(7<<18);  //���ͨ��16ԭ��������	 
//	ADC1->SMPR1|=7<<18;     //ͨ��16  239.5����,��߲���ʱ�������߾�ȷ��	 

//	ADC1->CR2|=1<<0;	   //����ADת����	 
//	ADC1->CR2|=1<<3;       //ʹ�ܸ�λУ׼  
//	while(ADC1->CR2&1<<3); //�ȴ�У׼���� 			 
//  //��λ���������ò���Ӳ���������У׼�Ĵ�������ʼ�����λ��������� 		 
//	ADC1->CR2|=1<<2;        //����ADУ׼	   
//	while(ADC1->CR2&1<<2);  //�ȴ�У׼����
//	//��λ�����������Կ�ʼУ׼������У׼����ʱ��Ӳ�����  
//  
//  
//  
//  
//  
//  Battery.BatReal = 3.95;//��λΪv ���ʵ�ʵ�ѹ  У׼��ѹʱ�޸�
//  Battery.ADinput = 1.98;//��λΪv R15��R17���Ӵ���ѹ У׼��ѹʱ�޸�
//  Battery.ADRef   = 3.26;//��λΪv ��Ƭ�������ѹ   У׼��ѹʱ�޸�
//  Battery.Bat_K   = Battery.BatReal/Battery.ADinput;//�����ѹ����ϵ��
//  Battery.BatteryADmin = 2000;//��ѹ����ADֵ
//  
//  
//  
//  
//  printf("��ѹ���AD��ʼ���...\r\n");
//  
//}





////���ADCֵ
////ch:ͨ��ֵ 0~16
////����ֵ:ת�����
//uint16_t Get_Adc(uint8_t ch)   
//{

//}

////��ȡͨ��ch��ת��ֵ��ȡtimes��,Ȼ��ƽ�� 
////ch:ͨ�����
////times:��ȡ����
////����ֵ:ͨ��ch��times��ת�����ƽ��ֵ
//u16 Get_Adc_Average(u8 ch,u8 times)
//{
//	u32 temp_val=0;
//	u8 t;
//	for(t=0;t<times;t++)
//	{
//		temp_val+=Get_Adc(ch);
//	}
//	return temp_val/times;
//} 

////�õ�ADC�����ڲ��¶ȴ��������¶�ֵ
////����ֵ3λ�¶�ֵ XXX*0.1C	 
//int Get_Temp(void)
//{				 
//	u16 temp_val=0;
//	u8 t;
//	float temperate;   
//	for(t=0;t<20;t++)//��20��,ȡƽ��ֵ
//	{
//		temp_val+=Get_Adc(16);//�¶ȴ�����Ϊͨ��16
//	}
//	temp_val/=20;
//	temperate=(float)temp_val*(3.3/4096);//�õ��¶ȴ������ĵ�ѹֵ
//	temperate=(1.43-temperate)/0.0043+25;//�������ǰ�¶�ֵ	 
//	temperate*=10;//����ʮ��,ʹ��С�����һλ
//	return (int)temperate;	 
//}


////���ص�ص�ѹADֵ
//int GetBatteryAD()
//{
// return Get_Adc_Average(8,5);
//}


////����ص�ѹ
//void BatteryCheck(void)
//{
//		Battery.BatteryAD  = GetBatteryAD();            //��ص�ѹ���  
//		Battery.BatteryVal = Battery.Bat_K * (Battery.BatteryAD/4096.0) * Battery.ADRef;//ʵ�ʵ�ѹ ֵ����	
//	  if(FLY_ENABLE)
//		{
//			if(Battery.BatteryAD <= Battery.BatteryADmin)
//			{
//					Battery.alarm=1;
//			}
//			else
//					Battery.alarm=0;
//		}
//		else
//		{
//			if((Battery.BatteryVal < BAT_ALARM_VAL)&&(Battery.BatteryVal > BAT_CHG_VAL))	//����3.7v �Ҵ��ڳ�����ѹ BAT_CHG_VAL
//				Battery.alarm=1;
//			else
//				Battery.alarm=0;
//		}
//		
//		if(Battery.BatteryVal < BAT_CHG_VAL) //on charge
//		{
//			Battery.chargeSta = 1; 
//		
//		}
//		else 					
//			Battery.chargeSta = 0;

//}


