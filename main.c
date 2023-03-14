#include <assert.h>
#include <string.h>
#include "checker.h"
#include "language.h"

batteryParam_t batteryParameters[PARAM_COUNT] =
{
	[TEMPERATURE] =		{.lowThreshold = 0.0F,	.hiThreshold = 45.0F,	.hasWarning = 1},
	[STATE_OF_CHARGE] =	{.lowThreshold = 20.0F,	.hiThreshold = 80.0F,	.hasWarning = 1},
	[CHARGE_RATE] =		{.lowThreshold = 0.0F,	.hiThreshold = 0.8F,	.hasWarning = 1},
};

float testBatteryReadings[8][3] =
{
	{44.0F, 22.0F, 0.6F},
	{20.0F, 35.0F, 0.85F},
	{20.0F, 91.0F, 0.6F},
	{20.0F, 91.0F, 0.85F},
	{63.0F, 35.0F, 0.6F},
	{63.0F, 35.0F, 0.85F},
	{63.0F, 91.0F, 0.6F},
	{63.0F, 91.0F, 0.85F}
};

void InitParamNames(void)
{
	int i = 0;

	for (i = 0; i < PARAM_COUNT; i++)
	{
		batteryParameters[i].name = paramNames[language][i];
	}
}

int main(void) {

	InitParamNames();

	assert(BatteryIsOk(testBatteryReadings[0]));

	for (int i = 1; i < 8; i++)
	{
		assert(!BatteryIsOk(testBatteryReadings[i]));
	}

	return 0;
}
