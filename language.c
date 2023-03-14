#include "language.h"

const enum languages_e language = GERMAN;

char paramNames[LANGUAGE_COUNT][PARAM_COUNT][20] =
{
	[ENGLISH] =	{"Temperature",	"State of charge",	"Charge rate"},
	[GERMAN] =	{"Temperatur",	"Ladezustand",		"Laderate"}
};

char tempNames[LANGUAGE_COUNT][20] =
{
	[ENGLISH] =	{"Temperature"},
	[GERMAN] =	{"Temperatur"}
};

char alertMsgs[LANGUAGE_COUNT][70] =
{
	[ENGLISH] =	{"%s is %.1f, outside the recommended range of %.1f - %.1f!\n"},
	[GERMAN] =	{"%s ist %.1f, außerhalb des empfohlenen Bereichs von %.1f - %.1f!\n"}
};

char lowWarningMsgs[LANGUAGE_COUNT][70] =
{
	[ENGLISH] =	{"Warning: %s is approaching low tolerance limit\n"},
	[GERMAN] =	{"Warnung: %s nähert sich der unteren Toleranzgrenze\n"}
};

char highWarningMsgs[LANGUAGE_COUNT][70] =
{
	[ENGLISH] =	{"Warning: %s is approaching high tolerance limit\n"},
	[GERMAN] =	{"Warnung: %s nähert sich der oberen Toleranzgrenze\n"}
};

char okMsgs[LANGUAGE_COUNT][70] =
{
	[ENGLISH] =	{"Battery status is OK\n"},
	[GERMAN] =	{"Batteriestatus ist in Ordnung\n"}
};

char notOKMsgs[LANGUAGE_COUNT][70] =
{
	[ENGLISH] =	{"Battery status is NOT OK, please address failures\n"},
	[GERMAN] =	{"Der Batteriestatus ist NICHT OK, bitte beheben Sie Fehler\n"}
};


