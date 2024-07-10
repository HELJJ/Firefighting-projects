#ifndef __App_h
#define __App_h
#include "main.h"
#include "stdio.h"

#define Resistor  100  //采样电阻大小
#define RefV 3.28

typedef enum
{
    LineShort = 0x01U,/*线短路*/
    LineOpen =0x02U,  /*线断路 */
    LineOn =0x03U, /*开关闭合*/
    LineOff =0x04U, /*开关断开*/
    LineNormal =0x05U, /*线路正常*/
    LineGuzhang =0x06U, /*线路故障*/
    LineLook=0x07U,/*检线状态*/
    LineControl =0x08U,/*控制状态*/
} LineState;


typedef struct
{
    float LineV;//线电压值
    uint16_t LineAd;//线采集AD值
    uint8_t LineFlg;//线状态
    uint8_t LineFlgold;
} LineCheck;


typedef struct
{
    float LineV;//线电压值
    uint16_t LineAd;//线采集AD值
    uint8_t LineState;//控制或检测
    uint8_t LineFlg;//线状态
    uint8_t LineFlgold;//线状态
    uint8_t DCFState;//电磁阀状态

} DCF;

typedef struct
{
    uint8_t ButtonFlg;//按键状态1无动作 2短按  3长按
    uint16_t ButtonTime;//按键计时
    uint8_t But_now;//现在状态
    uint8_t But_old;//上次状态

} Resetbu ;


typedef struct
{
    uint8_t NorMalflg;//6Q 正常
    uint16_t Q6timeOut;//6Q失效计时
} Q6Q;


typedef struct
{
    uint8_t LineOpen;//电源开路
    uint8_t LineShort;//电源短路
    uint8_t OpenCount;//open标志计数
    uint8_t OpenFlg[3];//open标志
} PowerLine_flg;


typedef struct
{
    uint8_t Dogflg;
    uint8_t CanCount;
    uint8_t Powerflg;
    uint8_t MBpower;
    uint8_t A6_state;
    uint16_t Servel;
} Sys_flg;





#pragma pack(1)
typedef struct
{
    uint8_t Head1;//头1
    uint8_t Head2;//头2
    uint8_t Len;//长度
    uint8_t SWadd;//拨码开关
    uint8_t Dogflg;//看门狗状态
    uint8_t Fback_State;//反馈阀状态
    uint8_t DCF_State;//电磁阀状态
    uint8_t Reset_State;//复位按键状态
    uint8_t CanCount;//CAN电平计数
    uint8_t PowerFlg;//电源线状态
    uint8_t MBpower;//主备电状态
    uint8_t rev;//备用
    uint16_t Serial;//序列号
    uint8_t SendMode;//发送模式
    uint8_t S_CRC;//CRC校验值
} TXmode;
typedef struct
{
    uint8_t Head1;//头1
    uint8_t Head2;//头2
    uint8_t Len;//长度
    uint8_t DogCtr;//看门狗状态
    uint8_t A6_State;//6A状态
    uint8_t Fault_State;//故障状态
    uint8_t Alarm_State;//报警状态
    uint8_t Miehuo_State;//灭火状态.
    uint8_t Q6Reset_State;//6Q复位标志
    uint8_t Mainten_State;//维护状态
    uint8_t ClearDog;//清狗指令
    uint8_t rev;//备用
    uint16_t Serial;//序列号
    uint8_t SendMode;//发送模式
    uint8_t S_CRC;//CRC校验值
} Rxmode;
#pragma pack()


extern LineCheck Fback;//反馈阀
extern DCF DCFState;//电磁阀状态
extern uint16_t ADCGet[5];//存储AD采集值
extern Resetbu ResButton;//复位按键判断
extern TXmode ReportInfo;//上报信息结构
extern Rxmode ReceiveInfo;//接收信息结构
extern uint16_t Systime;//发送计时用
extern uint16_t TXservel;//发送序列号
extern Q6Q Q6State;//6Q状态
extern uint16_t ADCGet[5];//存储AD采集值
extern uint8_t HostAddr;//主机地址
extern PowerLine_flg PowerLine;//电源线状态
extern Sys_flg SysDate;//系统信息





void delay_us( uint32_t tt );
void delay_ms( uint32_t tt );
void Sleep(void);
void SysTemInit(void);
uint8_t GetSensorAdd(void);
void GetAddr(void);
void SensorCheck(void);

uint8_t SendSensorState(uint16_t Servel,uint8_t Mode,uint16_t timeout);

void DelRxdate(void);

void DogOn(void);

void DogOff(void);














#endif /* __stdint_h */
















