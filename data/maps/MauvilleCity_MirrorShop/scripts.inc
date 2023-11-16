MauvilleCity_MirrorShop_MapScripts::
	.byte 0

MauvilleCity_MirrorShop_EventScript_Woman::
	lock
	checkitem ITEM_REVEAL_GLASS
	switch VAR_RESULT
	case TRUE, MauvilleCity_MirrorShop_EventScript_TryMirrorYet
	case FALSE, MauvilleCity_MirrorShop_EventScript_NoRevealGlass
    goto MauvilleCity_MirrorShop_EventScript_WomanSellMirrors

MauvilleCity_MirrorShop_EventScript_WomanSellMirrors::
	msgbox MauvilleCity_MirrorShop_Text_SellMirrorsOnly, MSGBOX_DEFAULT
	release
	end

MauvilleCity_MirrorShop_EventScript_NoRevealGlass::
    setvar VAR_PARTY_POKEMON_CHECK, 641
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_MirrorShop_EventScript_GiveRevealGlass
    setvar VAR_PARTY_POKEMON_CHECK, 642
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_MirrorShop_EventScript_GiveRevealGlass
    setvar VAR_PARTY_POKEMON_CHECK, 645
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_MirrorShop_EventScript_GiveRevealGlass
    setvar VAR_PARTY_POKEMON_CHECK, 905
    specialvar VAR_RESULT, CheckPartyPokemon
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_MirrorShop_EventScript_GiveRevealGlass
    setvar VAR_PARTY_POKEMON_CHECK, 0
    goto MauvilleCity_MirrorShop_EventScript_WomanSellMirrors

MauvilleCity_MirrorShop_EventScript_GiveRevealGlass::
    bufferspeciesname STR_VAR_1, VAR_PARTY_POKEMON_CHECK
    msgbox MauvilleCity_MirrorShop_Text_LegendaryPokemon, MSGBOX_DEFAULT
    giveitem ITEM_REVEAL_GLASS
    release
    end

MauvilleCity_MirrorShop_EventScript_TryMirrorYet::
	msgbox MauvilleCity_MirrorShop_Text_TryMirrorYet, MSGBOX_DEFAULT
	release
	end

MauvilleCity_MirrorShop_Text_SellMirrorsOnly:
	.string "Hi, there. Welcome!\n"
	.string "This is a specialty mirror store.\p"
	.string "Basically, we deal in mirrors and\n"
	.string "mirrors alone.\p"
	.string "We only exhibit and sell mirrors\n"
	.string "my husband collects from who\l"
	.string "knows where.\n"
	.string "So we don't have very many for sale.\p"
	.string "This mirror, by the way, is said to\n"
	.string "be used with Tornadus, Thundurus,\l"
	.string "Landorus and Enamorus.\p"
	.string "I have no idea if that's true.$"

MauvilleCity_MirrorShop_Text_LegendaryPokemon:
    .string "Hi, there. Welcome!\p"
    .string "Wait a sec! Don't tell me that you\n"
    .string "are with {STR_VAR_1}!\p"
    .string "Oh, my! That's awesome!\p"
    .string "This mirror is called Reveal Glass\n"
    .string "and it's said to be for {STR_VAR_1}\p"
    .string "You can have it. Feel free to use it!\n"
    .string "But don't tell my husband about it, okay?$"

MauvilleCity_MirrorShop_Text_TryMirrorYet:
    .string "Have you tried the mirror\n"
    .string "I gave you yet?\p"
    .string "I feel a bit bad for my husband, but items\n"
    .string "are useless unless you use them, right?\p"
    .string "Tee hee!\n"
    .string "Trainer, I'm cheering for you!$"
