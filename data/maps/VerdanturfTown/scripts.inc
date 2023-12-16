.set LOCALID_TWIN, 2
.set LOCALID_ALOLAN_BOY, 5
.set LOCALID_ALOLAN_DAD, 6
.set LOCALID_ALOLAN_MOM, 7
.set LOCALID_ALOLAN_GIRL, 8

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_AlolanFamily::
    goto_if_set FLAG_HIDE_ALOLAN_FAMILY, VerdanturfTown_EventScript_Nothing
    lockall
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceLeft
    waitmovement 0
    msgbox VerdanturfTown_Text_DiscussIssue, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceDown
    waitmovement 0
    msgbox VerdanturfTown_Text_AlreadyToldYou, MSGBOX_DEFAULT
    playse SE_SELECT
    waitse
    playse SE_PIN
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_ExclamationMark
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_ExclamationMark
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_ExclamationMark
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_FacePlayer
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_FacePlayer
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_FacePlayer
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_FacePlayer
    waitmovement 0
    playse SE_SELECT
    goto_if_eq VAR_ALOLAN_MAN_SAD, 1, VerdanturfTown_EventScript_AlolanFamilyDad
    goto_if_set FLAG_ORICORIO_KNOWLEDGE, VerdanturfTown_EventScript_AlolanFamilyGirl2
    goto_if_set FLAG_LIKE_ORICORIO, VerdanturfTown_EventScript_AlolanFamilyBoy2
    msgbox VerdanturfTown_Text_WhoAreYou, MSGBOX_DEFAULT
    setflag FLAG_HIDE_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_AlolanFamilyDad:: @ Plays this script if dad was talked to
    msgbox VerdanturfTown_Text_HeyItsYou, MSGBOX_DEFAULT
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_YouKnowThem, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceLeft
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_FaceDown
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_FaceUp
    waitmovement 0
    msgbox VerdanturfTown_Text_YeahTheyHelpedMe, MSGBOX_DEFAULT
    playse SE_SELECT
    goto_if_set FLAG_ORICORIO_KNOWLEDGE, VerdanturfTown_EventScript_AlolanFamilyGirl
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_TheyProbablyDontKnow, MSGBOX_DEFAULT
    playse SE_SELECT
    goto_if_set FLAG_LIKE_ORICORIO, VerdanturfTown_EventScript_AlolanFamilyBoy3
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_FacePlayer
    waitmovement 0
    msgbox VerdanturfTown_Text_PleaseLeave, MSGBOX_DEFAULT
    release
    end

VerdanturfTown_EventScript_AlolanFamilyGirl:: @ Plays this script if girl was talked to
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_MeTooTheyKnowALot, MSGBOX_DEFAULT
    playse SE_SELECT
    goto_if_set FLAG_LIKE_ORICORIO, VerdanturfTown_EventScript_AlolanFamilyBoy
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_TheySeemHonest, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceUp
    waitmovement 0
    msgbox VerdanturfTown_Text_DontBeABaby, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_Dots, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_ALOLAN_BOY, VerdanturfTown_Movement_AlolanBoyExit
    waitmovement 0
    removeobject LOCALID_ALOLAN_BOY
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceDown
    waitmovement 0
    msgbox VerdanturfTown_Text_NotVeryNice, MSGBOX_DEFAULT
    setflag FLAG_HIDE_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_AlolanFamilyGirl2:: @ Plays this script if Dad wasnt talked to
    msgbox VerdanturfTown_Text_HiTherePlayer, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_WhoIsThat, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceLeft
    waitmovement 0
    msgbox VerdanturfTown_Text_TheyHaveOricorio, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_FaceUp
    waitmovement 0
    goto_if_set FLAG_LIKE_ORICORIO, VerdanturfTown_EventScript_AlolanFamilyBoy4
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_TheySeemHonest, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_IDontTrustThis, MSGBOX_DEFAULT
    playse SE_SELECT
    closemessage
    applymovement LOCALID_ALOLAN_DAD, VerdanturfTown_Movement_AlolanDadExit
    waitmovement 0
    removeobject LOCALID_ALOLAN_DAD
    msgbox VerdanturfTown_Text_Sigh, MSGBOX_DEFAULT
    closemessage
    setflag FLAG_HIDE_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_AlolanFamilyBoy::
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_TheyLikeMyOricorio, MSGBOX_DEFAULT
    playse SE_SELECT
    waitse
    playse SE_PIN
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_ExclamationMark
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_WalkInPlaceRight
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_FaceLeft
    waitmovement 0
    msgbox VerdanturfTown_Text_TheresNoWay, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceLeft
    waitmovement 0
    msgbox VerdanturfTown_Text_ButTheyWatchedMyDance, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceLeft
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceLeft
    waitmovement 0
    msgbox VerdanturfTown_Text_MomHey, MSGBOX_DEFAULT
    playse SE_SELECT
    waitse
    playse SE_PIN
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_ExclamationMark
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_ExclamationMark
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_FaceRight
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_FaceRight
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_FaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_WeCanLikeDifferentStyles, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_ReallyMom, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceDown
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_FaceDown
    waitmovement 0
    msgbox VerdanturfTown_Text_OfCourseSweetie, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceDown
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_FaceUp
    waitmovement 0
    msgbox VerdanturfTown_Text_IThinkSensuIsBestStill, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_WalkInPlaceUp
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_FaceLeft
    waitmovement 0
    msgbox VerdanturfTown_Text_MomIsRight, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceLeft
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_FaceRight
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_FaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_ThinkAboutThisCarefully, MSGBOX_DEFAULT
    playse SE_SELECT
    closemessage
    applymovement LOCALID_ALOLAN_DAD, VerdanturfTown_Movement_AlolanDadExit
    applymovement LOCALID_ALOLAN_BOY, VerdanturfTown_Movement_AlolanBoyExit
    applymovement LOCALID_ALOLAN_GIRL, VerdanturfTown_Movement_AlolanGirlExit
    waitmovement 0
    removeobject LOCALID_ALOLAN_DAD
    removeobject LOCALID_ALOLAN_BOY
    removeobject LOCALID_ALOLAN_GIRL
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_FacePlayer
    waitmovement 0
    msgbox VerdanturfTown_Text_ThankYouSoMuch, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_ALOLAN_MOM, VerdanturfTown_Movement_AlolanGirlExit
    waitmovement 0
    removeobject LOCALID_ALOLAN_MOM
    setflag FLAG_HIDE_ALOLAN_FAMILY
    setflag FLAG_HELPED_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_AlolanFamilyBoy2::
    msgbox VerdanturfTown_Text_WhoAreYou2, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceDown
    waitmovement 0
    msgbox VerdanturfTown_Text_OhIKnowThem, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceUp
    waitmovement 0
    msgbox VerdanturfTown_Text_YouShouldntTalkToStrangers, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_FacePlayer
    waitmovement 0
    msgbox VerdanturfTown_Text_PleaseLeave, MSGBOX_DEFAULT
    setflag FLAG_HIDE_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_AlolanFamilyBoy3::
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_TheyLikeMyOricorio, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_GIRL, Common_Movement_WalkInPlaceUp
    waitmovement 0
    msgbox VerdanturfTown_Text_DoesntMeanAnything, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_Dots, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_ALOLAN_BOY, VerdanturfTown_Movement_AlolanBoyExit
    waitmovement 0
    removeobject LOCALID_ALOLAN_BOY
    applymovement LOCALID_ALOLAN_MOM, Common_Movement_WalkInPlaceDown
    waitmovement 0
    msgbox VerdanturfTown_Text_NotVeryNice, MSGBOX_DEFAULT
    setflag FLAG_HIDE_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_AlolanFamilyBoy4::
    applymovement LOCALID_ALOLAN_BOY, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_TheyLikeMyOricorio, MSGBOX_DEFAULT
    playse SE_SELECT
    applymovement LOCALID_ALOLAN_DAD, Common_Movement_WalkInPlaceRight
    waitmovement 0
    msgbox VerdanturfTown_Text_IDontTrustThis, MSGBOX_DEFAULT
    playse SE_SELECT
    closemessage
    applymovement LOCALID_ALOLAN_DAD, VerdanturfTown_Movement_AlolanDadExit
    waitmovement 0
    removeobject LOCALID_ALOLAN_DAD
    msgbox VerdanturfTown_Text_Sigh, MSGBOX_DEFAULT
    closemessage
    setflag FLAG_HIDE_ALOLAN_FAMILY
    release
    end

VerdanturfTown_EventScript_Nothing::
    end

VerdanturfTown_Movement_AlolanDadExit:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_Movement_AlolanBoyExit:
	walk_left
	walk_left
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_Movement_AlolanGirlExit:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
	step_end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_AirCleanHere:
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse:
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

VerdanturfTown_Text_DiscussIssue:
    .string "Alright, we need to discuss what\n"
    .string "happened back at Slateport City.$"

VerdanturfTown_Text_AlreadyToldYou:
    .string "I already told you, mom!\n"
    .string "The Sensu Style is the best!$"

VerdanturfTown_Text_HeyItsYou:
    .string "Hey, it's you…$"

VerdanturfTown_Text_YouKnowThem:
    .string "You know this person!?$"

VerdanturfTown_Text_YeahTheyHelpedMe:
    .string "Yeah! They helped me out back in\n"
    .string "Slateport with something…$"

VerdanturfTown_Text_MeTooTheyKnowALot:
    .string "I know them too. They sure know a\n"
    .string "lot about Oricorio! It's so cool that\l"
    .string "someone from Hoenn knows so much!$"

VerdanturfTown_Text_HiTherePlayer:
    .string "Oh hi there!$"

VerdanturfTown_Text_TheySeemHonest:
    .string "They seem pretty honest…$"

VerdanturfTown_Text_TheyLikeMyOricorio:
    .string "They like my Oricorio!$"

VerdanturfTown_Text_TheresNoWay:
    .string "There's no way they do. They told\n"
    .string "me they like MY Oricorio!$"

VerdanturfTown_Text_ButTheyWatchedMyDance:
    .string "But they watched my dance…$"

VerdanturfTown_Text_MomHey:
    .string "Hey!!$"

VerdanturfTown_Text_WeCanLikeDifferentStyles:
    .string "You know, maybe they just like all\n"
    .string "of the different Oricorio Styles?\p"
    .string "You don't have to like one type.\n"
    .string "And maybe we should think the same.\p"
    .string "As much as I like Pa'u Style, I think\n"
    .string "the Pom-Pom Style is great, It's much\l"
    .string "more energetic, and sometimes I feel\p"
    .string "energetic too!$"

VerdanturfTown_Text_ReallyMom:
    .string "Really, Mom??\n"
    .string "Does that mean you like my dance too?$"

VerdanturfTown_Text_OfCourseSweetie:
    .string "Of course, sweetie!$"

VerdanturfTown_Text_IThinkSensuIsBestStill:
    .string "Well I still think that the Sensu\n"
    .string "Style is the best.$"

VerdanturfTown_Text_MomIsRight:
    .string "Your mother is right,\n"
    .string "We can have our favorites, but we must\l"
    .string "respect that everyone else has theirs.\p"
    .string "And maybe we should admire what it is\n"
    .string "about it that makes them like it so?$"

VerdanturfTown_Text_ThinkAboutThisCarefully:
    .string "Well said.\p"
    .string "Well, I hope everyone thinks about\n"
    .string "this carefully. Now, let's get back\l"
    .string "to work.$"

VerdanturfTown_Text_ThankYouSoMuch:
    .string "Thank you so much.$"

VerdanturfTown_Text_WhoAreYou:
    .string "Hey, who are you?\n"
    .string "This is a private conversation.\p"
    .string "Please leave.$"

VerdanturfTown_Text_WhoAreYou2:
    .string "Hey, who are you?\n"
    .string "This is a private conversa-$"

VerdanturfTown_Text_OhIKnowThem:
    .string "Oh I know them! They like my\n"
    .string "Oricorio too!$"

VerdanturfTown_Text_YouShouldntTalkToStrangers:
    .string "Hey, you shouldn't talk to\n"
    .string "strangers.$"

VerdanturfTown_Text_PleaseLeave:
    .string "Please leave.$"

VerdanturfTown_Text_WhoIsThat:
    .string "Who's that?$"

VerdanturfTown_Text_TheyHaveOricorio:
    .string "They have an Oricorio\p"
    .string "Also, they're pretty knowledgeable\n"
    .string "about Oricorio too!$"

VerdanturfTown_Text_TheyProbablyDontKnow:
    .string "Yeah, but they probably don't even\n"
    .string "know anything about Oricorio.$"

VerdanturfTown_Text_DoesntMeanAnything:
    .string "Doesn't mean anything if they\n"
    .string "know nothing.$"

VerdanturfTown_Text_Dots:
    .string "………$"

VerdanturfTown_Text_NotVeryNice:
    .string "That wasn't very nice of you.$"

VerdanturfTown_Text_DontBeABaby:
    .string "Oh come on, don't be a baby.$"

VerdanturfTown_Text_IDontTrustThis:
    .string "I don't trust this. Why does\n"
    .string "everyone know them except me?\p"
    .string "You're all teaming against me.$"

VerdanturfTown_Text_Sigh:
    .string "Sigh…$"
