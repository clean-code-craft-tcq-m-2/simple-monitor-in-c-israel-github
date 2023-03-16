#include <stdio.h>
#include <string.h>
#include "checker.h"
#include "language.h"


void Alerter(batteryParam_t param, float reading)
{
	printf(alertMsgs[language], param.name, reading, param.lowThreshold, param.hiThreshold);
}

void WarningCheck(batteryParam_t param, float reading)
{
	float tolerance = param.hiThreshold * 0.05F;

	if ((reading >= param.lowThreshold) && (reading <= (param.lowThreshold + tolerance)))
	{
		printf(lowWarningMsgs[language], param.name);
	}
	else if ((reading <= param.hiThreshold) && (reading >= (param.hiThreshold - tolerance)))
	{
		printf(highWarningMsgs[language], param.name);
	}
}

int ParamIsOk(batteryParam_t param, float reading)
{
	if (reading < param.lowThreshold || reading > param.hiThreshold)
	{
		Alerter(param, reading);
		return 0;
	}
	else
	{
		return 1;
	}
}

void PrintStatusMsg(int result)
{
	if (result < PARAM_COUNT)
	{
		printf(notOKMsgs[language]);
	}
	else
	{
		printf(okMsgs[language]);
	}
}

int BatteryCheck(float batteryReadings[])
{
	int result = 0;
	int i = 0;

	for (i = 0; i < PARAM_COUNT; i++)
	{
		if (batteryParameters[i].hasWarning != 0)
		{
			WarningCheck(batteryParameters[i], batteryReadings[i]);
		}

		result += ParamIsOk(batteryParameters[i], batteryReadings[i]);
	}

	PrintStatusMsg(result);
	return result;
}