#ifndef __App_h
#define __App_h
#include "main.h"
#include "stdio.h"

#define Resistor  100  //���������С
#define RefV 3.28

typedef enum
{
    LineShort = 0x01U,/*�߶�·*/
    LineOpen =0x02U,  /*�߶�· */
    LineOn =0x03U, /*���رպ�*/
    LineOff =0x04U, /*���ضϿ�*/
    LineNormal =0x05U, /*��·����*/
    LineGuzhang =0x06U, /*��·����*/
    LineLook=0x07U,/*����״̬*/
    LineControl =0x08U,/*����״̬*/
} LineState;


typedef struct
{
    float LineV;//�ߵ�ѹֵ
    uint16_t LineAd;//�߲ɼ�ADֵ
    uint8_t LineFlg;//��״̬
    uint8_t LineFlgold;
} LineCheck;


typedef struct
{
    float LineV;//�ߵ�ѹֵ
    uint16_t LineAd;//�߲ɼ�ADֵ
    uint8_t LineState;//���ƻ���
    uint8_t LineFlg;//��״̬
    uint8_t LineFlgold;//��״̬
    uint8_t DCFState;//��ŷ�״̬

} DCF;

typedef struct
{
    uint8_t ButtonFlg;//����״̬1�޶��� 2�̰�  3����
    uint16_t ButtonTime;//������ʱ
    uint8_t But_now;//����״̬
    uint8_t But_old;//�ϴ�״̬

} Resetbu ;


typedef struct
{
    uint8_t NorMalflg;//6Q ����
    uint16_t Q6timeOut;//6QʧЧ��ʱ
} Q6Q;


typedef struct
{
    uint8_t LineOpen;//��Դ��·
    uint8_t LineShort;//��Դ��·
    uint8_t OpenCount;//open��־����
    uint8_t OpenFlg[3];//open��־
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
    uint8_t Head1;//ͷ1
    uint8_t Head2;//ͷ2
    uint8_t Len;//����
    uint8_t SWadd;//���뿪��
    uint8_t Dogflg;//���Ź�״̬
    uint8_t Fback_State;//������״̬
    uint8_t DCF_State;//��ŷ�״̬
    uint8_t Reset_State;//��λ����״̬
    uint8_t CanCount;//CAN��ƽ����
    uint8_t PowerFlg;//��Դ��״̬
    uint8_t MBpower;//������״̬
    uint8_t rev;//����
    uint16_t Serial;//���к�
    uint8_t SendMode;//����ģʽ
    uint8_t S_CRC;//CRCУ��ֵ
} TXmode;
typedef struct
{
    uint8_t Head1;//ͷ1
    uint8_t Head2;//ͷ2
    uint8_t Len;//����
    uint8_t DogCtr;//���Ź�״̬
    uint8_t A6_State;//6A״̬
    uint8_t Fault_State;//����״̬
    uint8_t Alarm_State;//����״̬
    uint8_t Miehuo_State;//���״̬.
    uint8_t Q6Reset_State;//6Q��λ��־
    uint8_t Mainten_State;//ά��״̬
    uint8_t ClearDog;//�幷ָ��
    uint8_t rev;//����
    uint16_t Serial;//���к�
    uint8_t SendMode;//����ģʽ
    uint8_t S_CRC;//CRCУ��ֵ
} Rxmode;
#pragma pack()


extern LineCheck Fback;//������
extern DCF DCFState;//��ŷ�״̬
extern uint16_t ADCGet[5];//�洢AD�ɼ�ֵ
extern Resetbu ResButton;//��λ�����ж�
extern TXmode ReportInfo;//�ϱ���Ϣ�ṹ
extern Rxmode ReceiveInfo;//������Ϣ�ṹ
extern uint16_t Systime;//���ͼ�ʱ��
extern uint16_t TXservel;//�������к�
extern Q6Q Q6State;//6Q״̬
extern uint16_t ADCGet[5];//�洢AD�ɼ�ֵ
extern uint8_t HostAddr;//������ַ
extern PowerLine_flg PowerLine;//��Դ��״̬
extern Sys_flg SysDate;//ϵͳ��Ϣ





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
















