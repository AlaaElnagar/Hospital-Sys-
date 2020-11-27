typedef struct Node_t
{
	u32 ID;
	u8 name[20];
	u32 age;
	u8 gender;
	struct Node_t* Next;
}Node;
        void ScreenInit(void);
        u8   ModeSelect(void);
static  void   AddNode(u32 ID,u8 name[20],u32 age,u8 gender);
static  void   PrintLinkedList(void);
static  u8     Search(u8 ID);
static  void   Edit(void);
static  void   GetPatientRecord(void);
static  void   PrintReservationtime(void);
static  void   ReservingTimeSlot(void);
static  void   AdminCheck(void);
static  void   AdminChoices(void);
static  void   RecivingPatientData(void);
static  void   UserChoice(void);

static  u32 login;
static  u32 AdminOperationSelect=1;
static  u32 UserOperationSelect=1;
static  u32 ReservationArray[5];
static  u8 Time_Slots[5][30]= {{"2:00 pm to 2:30 pm Press : 1"},    /* Time Slots of Reservation */
                    {"2:30 pm to 3:00 pm Press : 2"},
                    {"3:00 pm to 3:30 pm Press : 3"},
                    {"3:30 pm to 4:00 pm Press : 4"},
                    {"4:00 pm to 4:30 pm Press : 5"}
                    };


Node *Head = NULL;


