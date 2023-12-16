#include "global.h"
#include "play_time.h"
#include "rtc.h"
#include "main.h"

enum
{
    STOPPED,
    RUNNING,
    MAXED_OUT
};

static struct Time antiCheatTime;

static u8 sPlayTimeCounterState;

void PlayTimeCounter_Reset(void)
{
    sPlayTimeCounterState = STOPPED;

    gSaveBlock2Ptr->playTimeHours = 0;
    gSaveBlock2Ptr->playTimeMinutes = 0;
    gSaveBlock2Ptr->playTimeSeconds = 0;
    gSaveBlock2Ptr->playTimeVBlanks = 0;
}

void PlayTimeCounter_Start(void)
{
    sPlayTimeCounterState = RUNNING;

    if (gSaveBlock2Ptr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_Stop(void)
{
    sPlayTimeCounterState = STOPPED;
}

void PlayTimeCounter_Update(void)
{
    struct Time timeDiff;

    if (sPlayTimeCounterState != RUNNING)
        return;

    gSaveBlock2Ptr->playTimeVBlanks++;

    if (gSaveBlock2Ptr->playTimeVBlanks < 60)
        return;

    // Reset the game if an in battle state is loaded
    RtcCalcLocalTime();
    CalcTimeDifference(&timeDiff, &antiCheatTime, &gLocalTime);
    if (gMain.inBattle && (abs(timeDiff.seconds) > 6 || abs(timeDiff.minutes) > 1 || abs(timeDiff.hours) > 1 || abs(timeDiff.days) > 1))
        DoSoftReset();
    antiCheatTime = gLocalTime;

    gSaveBlock2Ptr->playTimeVBlanks = 0;
    gSaveBlock2Ptr->playTimeSeconds++;

    if (gSaveBlock2Ptr->playTimeSeconds < 60)
        return;

    gSaveBlock2Ptr->playTimeSeconds = 0;
    gSaveBlock2Ptr->playTimeMinutes++;

    if (gSaveBlock2Ptr->playTimeMinutes < 60)
        return;

    gSaveBlock2Ptr->playTimeMinutes = 0;
    gSaveBlock2Ptr->playTimeHours++;

    if (gSaveBlock2Ptr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_SetToMax(void)
{
    sPlayTimeCounterState = MAXED_OUT;

    gSaveBlock2Ptr->playTimeHours = 999;
    gSaveBlock2Ptr->playTimeMinutes = 59;
    gSaveBlock2Ptr->playTimeSeconds = 59;
    gSaveBlock2Ptr->playTimeVBlanks = 59;
}
