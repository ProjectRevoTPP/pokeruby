Route113_MapObjects:: @ 83829A0
	object_event 1, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 66, 0, 12, 0, 3, 5, 1, 0, 0, 0, 0, 0, Route113_EventScript_15060E, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GENTLEMAN, 0, 36, 0, 10, 0, 3, 3, 16, 0, 0, 0, 0, 0, Route113_EventScript_150605, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_YOUNGSTER, 0, 62, 0, 8, 0, 3, 8, 0, 0, 1, 0, 3, 0, Route113_EventScript_15063B, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_YOUNGSTER, 0, 21, 0, 11, 0, 3, 17, 0, 0, 1, 0, 3, 0, Route113_EventScript_150652, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_WOMAN_7, 0, 51, 0, 11, 0, 3, 23, 0, 0, 1, 0, 2, 0, Route113_EventScript_150669, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_ITEM_BALL, 0, 53, 0, 7, 0, 3, 1, 0, 0, 0, 0, 0, 0, Route113_EventScript_1B14FC, FLAG_ITEM_ROUTE113_1, 0, 0
	object_event 7, MAP_OBJ_GFX_ITEM_BALL, 0, 78, 0, 5, 0, 3, 1, 0, 0, 0, 0, 0, 0, Route113_EventScript_1B1509, FLAG_ITEM_ROUTE113_2, 0, 0
	object_event 8, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 66, 0, 3, 0, 3, 63, 0, 0, 3, 0, 1, 0, Route113_EventScript_1506A7, 0, 0, 0
	object_event 9, MAP_OBJ_GFX_LITTLE_BOY_1, 0, 29, 0, 6, 0, 3, 63, 0, 0, 3, 0, 1, 0, Route113_EventScript_1506E5, 0, 0, 0
	object_event 10, MAP_OBJ_GFX_LITTLE_GIRL_1, 0, 45, 0, 6, 0, 3, 8, 17, 0, 1, 0, 0, 0, Route113_EventScript_1506FC, 0, 0, 0
	object_event 11, MAP_OBJ_GFX_LITTLE_GIRL_1, 0, 46, 0, 6, 0, 3, 8, 17, 0, 1, 0, 0, 0, Route113_EventScript_150717, 0, 0, 0

Route113_MapWarps:: @ 8382AA8
	warp_def 33, 5, 0, 0, MAP_ROUTE113_GLASS_WORKSHOP

Route113_MapCoordEvents:: @ 8382AB0
	coord_weather_event 19, 11, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 19, 10, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 19, 12, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 19, 13, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 87, 9, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 86, 10, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 86, 11, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 14, 10, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 14, 11, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 14, 12, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 14, 13, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 8, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 9, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 10, 3, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 94, 11, 0, COORD_EVENT_WEATHER_SUNNY
	coord_weather_event 19, 14, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 88, 8, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 88, 6, 3, COORD_EVENT_WEATHER_ASH
	coord_weather_event 88, 7, 3, COORD_EVENT_WEATHER_ASH

Route113_MapBGEvents:: @ 8382BE0
	bg_event 85, 6, 0, 0, 0, Route113_EventScript_150617
	bg_event 11, 9, 0, 0, 0, Route113_EventScript_150620
	bg_event 58, 4, 3, 0, 0, Route113_EventScript_150632
	bg_event 31, 5, 0, 0, 0, Route113_EventScript_150629
	bg_secret_base_event 49, 8, 0, SECRET_BASE_RED_CAVE1_3
	bg_hidden_item_event 72, 4, 3, ITEM_ETHER, FLAG_HIDDEN_ITEM_3
	bg_hidden_item_event 22, 5, 3, ITEM_TM32, FLAG_HIDDEN_ITEM_1E

Route113_MapEvents:: @ 8382C34
	map_events Route113_MapObjects, Route113_MapWarps, Route113_MapCoordEvents, Route113_MapBGEvents
