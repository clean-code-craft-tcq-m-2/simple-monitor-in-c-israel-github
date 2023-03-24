enum languages_e
{
	ENGLISH,
	GERMAN,
	LANGUAGE_COUNT
};

enum parameters_e
{
	TEMPERATURE,
	STATE_OF_CHARGE,
	CHARGE_RATE,
	PARAM_COUNT
};

extern const enum languages_e language;

extern char paramNames[LANGUAGE_COUNT][PARAM_COUNT][20];
extern char alertMsgs[LANGUAGE_COUNT][70];
extern char lowWarningMsgs[LANGUAGE_COUNT][70];
extern char highWarningMsgs[LANGUAGE_COUNT][70];
extern char okMsgs[LANGUAGE_COUNT][70];
extern char notOKMsgs[LANGUAGE_COUNT][70];
extern char tempNames[LANGUAGE_COUNT][20];
