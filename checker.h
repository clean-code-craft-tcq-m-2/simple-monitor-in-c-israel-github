typedef struct batteryParam_s
{
	char* name;
	float lowThreshold;
	float hiThreshold;
	int hasWarning;
} batteryParam_t;

extern batteryParam_t batteryParameters[];

void Alerter(batteryParam_t param, float level);
void PrintStatusMsg(int result);
void WarningCheck(batteryParam_t param, float level);
int ParamIsOk(batteryParam_t param, float level);
int BatteryCheck(float batteryLevels[]);