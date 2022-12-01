#include <stdio.h>
#include <assert.h>

#define NUM_OF_PARAMETERS	3

typedef struct batteryParam_s
{
	char name[20];
	float lowThreshold;
	float hiThreshold;
} batteryParam_t;

const batteryParam_t batteryParameters[NUM_OF_PARAMETERS] =
{
	{"Temperature", 0.0F, 45.0F},
	{"State of charge", 20.0F, 80.0F},
	{"Charge rate", 0.0F, 0.8F}
};

const float testBatteryReadings[8][NUM_OF_PARAMETERS] =
{
	{20.0F, 35.0F, 0.6F},
	{20.0F, 35.0F, 0.85F},
	{20.0F, 91.0F, 0.6F},
	{20.0F, 91.0F, 0.85F},
	{63.0F, 35.0F, 0.6F},
	{63.0F, 35.0F, 0.85F},
	{63.0F, 91.0F, 0.6F},
	{63.0F, 91.0F, 0.85F}
};


void alerter(const batteryParam_t param, const float level)
{
	printf("%s is %.1f, out of recommended range of %.1f - %.1f!\n", param.name, level, param.lowThreshold, param.hiThreshold);
}

int paramCheck(const batteryParam_t param, const float level)
{
	if (level < param.lowThreshold || level > param.hiThreshold)
	{
		alerter(param, level);
		return 1;
	}
	else
	{
		return 0;
	}
}

int batteryIsOk(const float batteryLevels[]) {
	int result = 0;
	int i = 0;

	for (i = 0; i < NUM_OF_PARAMETERS; i++)
	{
		result += paramCheck(batteryParameters[i], batteryLevels[i]);
	}

	if (result == 0)
	{
		printf("Battery status is OK\n");
		return 1;
	}
	else
	{
		printf("Battery status is NOT OK, please address failures\n");
		return 0;
	}
}

int main() {

	assert(batteryIsOk(testBatteryReadings[0]));

	for (int i = 1; i < 8; i++)
	{
		assert(!batteryIsOk(testBatteryReadings[i]));
	}

	return 0;
}
