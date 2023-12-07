.set LOCALID_ITEM_BALL, 1
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
    goto_if_set FLAG_REDUCED_PRICE, LilycoveCity_AntiquesShop_EventScript_SellForReducedPrice
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
    showmoneybox 0, 0
    msgbox LilycoveCity_AntiquesShop_Text_BuySwordOrShield, MSGBOX_DEFAULT
    dynmultichoice 6, 6, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, LilycoveCity_AntiquesShop_Text_Option_1, LilycoveCity_AntiquesShop_Text_Option_2, LilycoveCity_AntiquesShop_Text_Option_3, LilycoveCity_AntiquesShop_Text_Option_4
    switch VAR_RESULT
    case 0, LilycoveCity_AntiquesShop_EventScript_BuyOnlySword
    case 1, LilycoveCity_AntiquesShop_EventScript_BuyOnlyShield
    case 2, LilycoveCity_AntiquesShop_EventScript_BuyBothSwordAndShield
    case 3, LilycoveCity_AntiquesShop_EventScript_CancelBuy
    case MULTI_B_PRESSED, LilycoveCity_AntiquesShop_EventScript_CancelBuy
    release
    end

LilycoveCity_AntiquesShop_EventScript_BuyOnlySword::
    checkmoney 10000
    goto_if_eq VAR_RESULT, 0, LilycoveCity_AntiquesShop_EventScript_NotEnoughMoney
    checkitemspace ITEM_RUSTED_SWORD
    call_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveMoney
    giveitem ITEM_RUSTED_SWORD
    goto_if_eq VAR_RESULT, FALSE, LilycoveCity_AntiquesShop_EventScript_NoBagSpace
    call_if_eq FLAG_RECEIVED_SHIELD, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveItemBall
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_Purchase, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_SWORD
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    return
LilycoveCity_AntiquesShop_EventScript_BuyOnlyShield::
    checkmoney 10000
    goto_if_eq VAR_RESULT, 0, LilycoveCity_AntiquesShop_EventScript_NotEnoughMoney
    checkitemspace ITEM_RUSTED_SHIELD
    call_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveMoney
    giveitem ITEM_RUSTED_SHIELD
    goto_if_eq VAR_RESULT, FALSE, LilycoveCity_AntiquesShop_EventScript_NoBagSpace
    call_if_eq FLAG_RECEIVED_SWORD, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveItemBall
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_Purchase, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_SHIELD
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    return

LilycoveCity_AntiquesShop_EventScript_BuyBothSwordAndShield::
    checkmoney 19000
    goto_if_eq VAR_RESULT, 0, LilycoveCity_AntiquesShop_EventScript_NotEnoughMoney
    checkitemspace ITEM_RUSTED_SHIELD
    call_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveMoney
    giveitem ITEM_RUSTED_SHIELD
    goto_if_eq VAR_RESULT, FALSE, LilycoveCity_AntiquesShop_EventScript_NoBagSpace
    checkitemspace ITEM_RUSTED_SWORD
    call_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveMoney2
    giveitem ITEM_RUSTED_SWORD
    goto_if_eq VAR_RESULT, FALSE, LilycoveCity_AntiquesShop_EventScript_NoBagSpace2
    call LilycoveCity_AntiquesShop_EventScript_RemoveItemBall
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_Purchase, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_SHIELD
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    release
    end
LilycoveCity_AntiquesShop_EventScript_SellForReducedPrice::
    msgbox LilycoveCity_AntiquesShop_Text_PurchaseReducedPrice, MSGBOX_DEFAULT
    checkmoney 9000
    goto_if_eq VAR_RESULT, 0, LilycoveCity_AntiquesShop_EventScript_NotEnoughMoney
    checkitemspace ITEM_RUSTED_SWORD
    call_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_RemoveMoney2
    giveitem ITEM_RUSTED_SWORD
    goto_if_eq VAR_RESULT, FALSE, LilycoveCity_AntiquesShop_EventScript_NoBagSpace2
    call LilycoveCity_AntiquesShop_EventScript_RemoveItemBall
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_Purchase, MSGBOX_DEFAULT
    setflag FLAG_RECEIVED_SHIELD
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_SpecialBuyShield::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    showmoneybox 0, 0
    msgbox LilycoveCity_AntiquesShop_Text_WantToBuyTheShield, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_AntiquesShop_EventScript_BuyOnlyShield
	goto_if_eq VAR_RESULT, NO, LilycoveCity_AntiquesShop_EventScript_CancelBuy
	release
	end
LilycoveCity_AntiquesShop_EventScript_SpecialBuySword::
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_WalkToPlayerBall
    waitmovement 0
    showmoneybox 0, 0
    msgbox LilycoveCity_AntiquesShop_Text_WantToBuyTheShield, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_AntiquesShop_EventScript_BuyOnlySword
	goto_if_eq VAR_RESULT, NO, LilycoveCity_AntiquesShop_EventScript_CancelBuy
	release
	end

LilycoveCity_AntiquesShop_EventScript_RemoveItemBall::
    setflag FLAG_HIDE_ANTIQUE_POKEBALL
    removeobject LOCALID_ITEM_BALL
    return

LilycoveCity_AntiquesShop_EventScript_CancelBuy::
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_CancelBuy, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_NotEnoughMoney::
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_NotEnoughMoney, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_NoBagSpace::
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_YourBagIsFull, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_NoBagSpace2::
    hidemoneybox
    msgbox LilycoveCity_AntiquesShop_Text_YourBagIsFull2, MSGBOX_DEFAULT
    setflag FLAG_REDUCED_PRICE
    closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
    release
    end

LilycoveCity_AntiquesShop_EventScript_RemoveMoney::
	removemoney 10000
	updatemoneybox
	return

LilycoveCity_AntiquesShop_EventScript_RemoveMoney2::
	removemoney 9000
	updatemoneybox
	return

LilycoveCity_AntiquesShop_EventScript_CheckPartyZamazenta::
    setvar VAR_PARTY_POKEMON_CHECK, 889
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveShield2
    setvar VAR_PARTY_POKEMON_CHECK, 0
    goto LilycoveCity_AntiquesShop_EventScript_SpecialBuyShield
    end
LilycoveCity_AntiquesShop_EventScript_CheckPartyZacian::
    setvar VAR_PARTY_POKEMON_CHECK, 888
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, LilycoveCity_AntiquesShop_EventScript_GiveSword2
    setvar VAR_PARTY_POKEMON_CHECK, 0
    goto LilycoveCity_AntiquesShop_EventScript_SpecialBuySword
    end

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
    removeobject LOCALID_ITEM_BALL
    setflag FLAG_HIDE_ANTIQUE_POKEBALL
    release
    end
LilycoveCity_AntiquesShop_EventScript_GiveShield3::
    msgbox LilycoveCity_AntiquesShop_Text_YouAlsoHaveShield, MSGBOX_DEFAULT
    giveitem ITEM_RUSTED_SHIELD
    setflag FLAG_RECEIVED_SHIELD
    setvar VAR_PARTY_POKEMON_CHECK, 0
    removeobject LOCALID_ITEM_BALL
    setflag FLAG_HIDE_ANTIQUE_POKEBALL
    release
    end

LilycoveCity_AntiquesShop_EventScript_Cabinet::
    lock
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_0, 11, LilycoveCity_AntiquesShop_EventScript_MoveToPlayerClose
    call_if_eq VAR_TEMP_0, 12, LilycoveCity_AntiquesShop_EventScript_MoveToPlayerFar
    waitmovement 0
    msgbox LilycoveCity_AntiquesShop_Text_InterestedInWhatsInTheCabinet, MSGBOX_DEFAULT
    waitmessage
	pokemart LilycoveCity_AntiquesShop_Mart_Pokemart
	msgbox LilycoveCity_AntiquesShop_Text_CancelBuy2, MSGBOX_DEFAULT
	closemessage
    applymovement LOCALID_SHOP_MAN, LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop
    waitmovement 0
	release
	end

	.align 2
LilycoveCity_AntiquesShop_Mart_Pokemart:
	.2byte ITEM_CRACKED_POT
	.2byte ITEM_UNREMARKABLE_TEACUP
	.2byte ITEM_CHIPPED_POT
	.2byte ITEM_MASTERPIECE_TEACUP
	.2byte ITEM_NONE
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

LilycoveCity_AntiquesShop_Movement_ReturnToCenterOfShop:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    face_down
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

LilycoveCity_AntiquesShop_Text_Option_1:
    .string "Sword$"

LilycoveCity_AntiquesShop_Text_Option_2:
    .string "Shield$"

LilycoveCity_AntiquesShop_Text_Option_3:
    .string "Both$"

LilycoveCity_AntiquesShop_Text_Option_4:
    .string "Never mind.$"

LilycoveCity_AntiquesShop_Text_Purchase:
    .string "Thanks for the buy.\n"
    .string "Enjoy. He-he.$"

LilycoveCity_AntiquesShop_Text_CancelBuy:
    .string "Oh, if you want anything else\n"
    .string "just let me know.$"

LilycoveCity_AntiquesShop_Text_NotEnoughMoney:
    .string "You can't afford this! You're\n"
    .string "flat broke! Ha-ha-ha!$"

LilycoveCity_AntiquesShop_Text_YourBagIsFull:
    .string "Your bag is full, come back\n"
    .string "once you make some space.$"

LilycoveCity_AntiquesShop_Text_YourBagIsFull2:
    .string "Your bag is full, come back\n"
    .string "once you make some space.\p"
    .string "Don't worry, I'll still give\n"
    .string "you the discounted price.$"

LilycoveCity_AntiquesShop_Text_PurchaseReducedPrice:
    .string "As promised, here's the Shield at\n"
    .string "the reduced price.$"

LilycoveCity_AntiquesShop_Text_WantToBuyTheShield:
    .string "Did you want to buy the Shield?$"

LilycoveCity_AntiquesShop_Text_InterestedInWhatsInTheCabinet:
    .string "Interested in what's inside the\n"
    .string "cabinet? Let me help you.\p"
    .string "Here's what we got.$"

LilycoveCity_AntiquesShop_Text_CancelBuy2:
    .string "Let me know if there's anything\n"
    .string "else you'd like.$"
