SeafloorCavern_Room8_MapObjects:: @ 838D4DC
	object_event 1, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 0, 7, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_11, 0, 0
	object_event 2, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 0, 7, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_12, 0, 0
	object_event 3, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 0, 7, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_13, 0, 0
	object_event 4, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 0, 6, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_14, 0, 0
	object_event 5, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 0, 6, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_15, 0, 0
	object_event 6, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 0, 5, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_16, 0, 0
	object_event 7, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 5, 0, 5, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_17, 0, 0
	object_event 8, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 0, 5, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_18, 0, 0
	object_event 9, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 3, 0, 4, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_19, 0, 0
	object_event 10, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 4, 0, 4, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_1A, 0, 0
	object_event 11, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 0, 4, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_1B, 0, 0
	object_event 12, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 0, 4, 0, 3, 1, 0, 0, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_1C, 0, 0

SeafloorCavern_Room8_MapWarps:: @ 838D5FC
	warp_def 5, 2, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM9
	warp_def 5, 12, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM3

SeafloorCavern_Room8_MapEvents:: @ 838D60C
	map_events SeafloorCavern_Room8_MapObjects, SeafloorCavern_Room8_MapWarps, 0x0, 0x0
