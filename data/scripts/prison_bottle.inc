PrisonBottle_OnTransition:
	call PrisonBottle_EventScript_HideOrShowPrisonBottleMan
	end

PrisonBottle_EventScript_HideOrShowPrisonBottleMan::
    goto_if_set FLAG_RECEIVED_PRISON_BOTTLE, PrisonBottle_EventScript_HidePrisonBottleMan
    setvar VAR_PARTY_POKEMON_CHECK, 720
    specialvar VAR_RESULT, CheckPartyPokemon
	goto_if_eq VAR_RESULT, TRUE, PrisonBottle_EventScript_ShowPrisonBottleMan
	goto PrisonBottle_EventScript_HidePrisonBottleMan
	end

PrisonBottle_EventScript_ShowPrisonBottleMan::
	clearflag FLAG_HIDE_POKEMART_PRISON_BOTTLE_MAN
	return

PrisonBottle_EventScript_HidePrisonBottleMan::
	setflag FLAG_HIDE_POKEMART_PRISON_BOTTLE_MAN
	return

PrisonBottle_EventScript_YouHaveHoopa::
    lock
    faceplayer
    setvar VAR_PARTY_POKEMON_CHECK, 0
    checkitem ITEM_PRISON_BOTTLE
    goto_if_eq VAR_RESULT, TRUE, PrisonBottle_EventScript_ReceivedPrisonBottle
    msgbox PrisonBottle_Text_HoopaStory, MSGBOX_DEFAULT
    msgbox PrisonBottle_Text_HoopaStory2, MSGBOX_DEFAULT
    msgbox PrisonBottle_Text_HoopaStory3, MSGBOX_DEFAULT
    msgbox PrisonBottle_Text_HoopaStory4, MSGBOX_DEFAULT
    msgbox PrisonBottle_Text_HoopaStory5, MSGBOX_DEFAULT
    giveitem ITEM_PRISON_BOTTLE
    setflag FLAG_RECEIVED_PRISON_BOTTLE
    msgbox PrisonBottle_Text_HoopaStoryDone, MSGBOX_DEFAULT
    release
    end

PrisonBottle_EventScript_ReceivedPrisonBottle::
    msgbox PrisonBottle_Text_HoopaStoryDone, MSGBOX_DEFAULT
    release
    end
