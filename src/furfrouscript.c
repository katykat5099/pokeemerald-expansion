#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"

void ChangeFurfrouFormHeart(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_HEART_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormStar(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_STAR_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormDiamond(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_DIAMOND_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormDebutante(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_DEBUTANTE_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormMatron(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_MATRON_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormDandy(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_DANDY_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormLaReine(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_LA_REINE_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormKabuki(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_KABUKI_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormPharaoh(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_PHARAOH_TRIM;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}

void ChangeFurfrouFormNatural(void)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES)) == SPECIES_FURFROU)
        {
                targetSpecies = SPECIES_FURFROU_NATURAL;
                SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
}
