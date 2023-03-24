#include <stdio.h>
#include <string.h>
#include "checker.h"
#include "language.h"


void Alerter(batteryParam_t param, float reading)
{
	printf(alertMsgs[language], param.name, reading, param.lowThreshold, param.hiThreshold);
}

int IsWithinLimits(float reading, float lowLimit, float hiLimit)
{
	if ((reading >= lowLimit) && (reading <= hiLimit))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void PrintWarningMsg(batteryParam_t param, float reading, float tolerance)
{
	if (reading < param.lowThreshold + tolerance)
	{
		printf(lowWarningMsgs[language], param.name);
	}
	else
	{
		printf(highWarningMsgs[language], param.name);
	}
}

void WarningCheck(batteryParam_t param, float reading)
{
	float tolerance = param.hiThreshold * 0.05F;

	if ((IsWithinLimits(reading, param.lowThreshold, param.lowThreshold + tolerance)) ||
		(IsWithinLimits(reading, param.hiThreshold - tolerance, param.hiThreshold)))
	{
		PrintWarningMsg(param, reading, tolerance);
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