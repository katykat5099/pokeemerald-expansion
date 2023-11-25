.set LOCALID_SHOP_MAN, 2

LilycoveCity_AntiquesShop_MapScripts::
	.byte 0

LilycoveCity_AntiquesShop_EventScript_TakeALookAround::
    msgbox LilycoveCity_AntiquesShop_Text_TakeALookAround, MSGBOX_NPC
    end

LilycoveCity_AntiquesShop_EventScript_BuySwordOrShield::
    lock
    goto_if_set FLAG_RECEIVED_SWORD, LilycoveCity_AntiquesShop_EventScript_CheckPartyZamazenta
    goto_if_set FLAG_RECEIVED_SHIELD, LilycoveCity_AntiquesShop_EventScript_CheckPartyZacian
    setvar VAR_PARTY_POKEMON_CHECK, 888
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveSword
    setvar VAR_PARTY_POKEMON_CHECK, 889
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveShield
    goto LilycoveCity_AntiquesShop_EventScript_BuySwordOrShield2
LilycoveCity_AntiquesShop_EventScript_BuySwordOrShield2::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    msgbox LilycoveCity_AntiquesShop_Text_BuySwordOrShield, MSGBOX_DEFAULT

LilycoveCity_AntiquesShop_EventScript_CheckPartyZamazenta::
    setvar VAR_PARTY_POKEMON_CHECK, 889
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveShield2
    return
LilycoveCity_AntiquesShop_EventScript_CheckPartyZacian::
    setvar VAR_PARTY_POKEMON_CHECK, 888
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveSword2
    return

LilycoveCity_AntiquesShop_EventScript_GiveSword::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_SHOP_MAN, Common_Movement_ExclamationMark
    msgbox LilycoveCity_AntiquesShop_Text_GiveSword, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SWORD
    msgbox LilycoveCity_AntiquesShop_Text_IfYouWantTheOtherOne, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_SWORD
    setvar VAR_PARTY_POKEMON_CHECK, 889
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveShield3
    setvar VAR_PARTY_POKEMON_CHECK, 0
    release
    end
LilycoveCity_AntiquesShop_EventScript_GiveShield::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_SHOP_MAN, Common_Movement_ExclamationMark
    msgbox LilycoveCity_AntiquesShop_Text_GiveShield, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SHIELD
    msgbox LilycoveCity_AntiquesShop_Text_IfYouWantTheOtherOne, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_SHIELD
    setvar VAR_PARTY_POKEMON_CHECK, 888
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveSword3
    setvar VAR_PARTY_POKEMON_CHECK, 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_GiveSword2::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_SHOP_MAN, Common_Movement_ExclamationMark
    msgbox LilycoveCity_AntiquesShop_Text_YouAlsoHaveSword, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SWORD
    setflag FLAG_RECEIVED_SWORD
    setvar VAR_PARTY_POKEMON_CHECK, 0
    release
    end
LilycoveCity_AntiquesShop_EventScript_GiveShield2::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_SHOP_MAN, Common_Movement_ExclamationMark
    msgbox LilycoveCity_AntiquesShop_Text_YouAlsoHaveShield, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SHIELD
    setflag FLAG_RECEIVED_SHIELD
    setvar VAR_PARTY_POKEMON_CHECK, 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_GiveSword3::
    msgbox LilycoveCity_AntiquesShop_Text_YouAlsoHaveSword, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SWORD
    setflag FLAG_RECEIVED_SWORD
    setvar VAR_PARTY_POKEMON_CHECK, 0
    release
    end
LilycoveCity_AntiquesShop_EventScript_GiveShield3::
    msgbox LilycoveCity_AntiquesShop_Text_YouAlsoHaveShield, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SHIELD
    setflag FLAG_RECEIVED_SHIELD
    setvar VAR_PARTY_POKEMON_CHECK, 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_Cabinet::
    lock
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_0, 11, LilycoveCity_AntiquesShop_EventScript_MoveToPlayerClose
    call_if_eq VAR_TEMP_0, 12, LilycoveCity_AntiquesShop_EventScript_MoveToPlayerFar
    release
    end

LilycoveCity_AntiquesShop_EventScript_MoveToPlayerClose::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerCloseCabinet
    return

LilycoveCity_AntiquesShop_EventScript_MoveToPlayerFar::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerFarCabinet
    return

LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall:
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

LilycoveCity_AntiquesShop_Movement_WalkToPlayerCloseCabinet:
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

LilycoveCity_AntiquesShop_Movement_WalkToPlayerFarCabinet:
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

LilycoveCity_AntiquesShop_Text_TakeALookAround:
    .string "Welcome to my Antiques shop!\n"
    .string "Please, take a look around.$"

LilycoveCity_AntiquesShop_Text_BuySwordOrShield:
    .string "Hi there! Are you interested in the\n"
    .string "Sword? I also have a Shield.\p"
    .string "You can buy separately for ¥10000,\n"
    .string "or together for ¥19000!$"

LilycoveCity_AntiquesShop_Text_GiveSword:
    .string "Welcome… Woah is that…\n"
    .string "Is that Zacian!?\p"
    .string "These artifacts I have here, they're\n"
    .string "said to summon the legendary Pokemon\l"
    .string "when in need! Well…\p"
    .string "I guess I was not in need. But, I\n"
    .string "think I bet Zacian is. Please, take it.\l"
    .string "For Zacian.$"
LilycoveCity_AntiquesShop_Text_GiveShield:
    .string "Welcome… Woah is that…\n"
    .string "Is that Zamazenta!?\p"
    .string "These artifacts I have here, they're\n"
    .string "said to summon the legendary Pokemon\l"
    .string "when in need! Well…\p"
    .string "I guess I was not in need. But, I\n"
    .string "think I bet Zamazenta is. Please, take it.\l"
    .string "For Zamazenta.$"

LilycoveCity_AntiquesShop_Text_YouAlsoHaveSword:
    .string "You're also with Zacian!?\n"
    .string "I'm so sorry, please, forgive me.\l"
    .string "Take it, Zacian. Spare me.$"
LilycoveCity_AntiquesShop_Text_YouAlsoHaveShield:
    .string "You're also with Zamazenta!?\n"
    .string "I'm so sorry, please, forgive me.\l"
    .string "Take it, Zamazenta. Spare me.$"

LilycoveCity_AntiquesShop_Text_IfYouWantTheOtherOne:
    .string "If you want the other one though,\n"
    .string "you'll have to buy it.$"
