#include <stdafx.h>

static void OnStart()
{
	Hash relationshipGroup;
	ADD_RELATIONSHIP_GROUP("_HOSTILE_RANDOM", &relationshipGroup);
	SET_RELATIONSHIP_BETWEEN_GROUPS(5, relationshipGroup, GET_HASH_KEY("PLAYER"));
	SET_RELATIONSHIP_BETWEEN_GROUPS(5, GET_HASH_KEY("PLAYER"), relationshipGroup);

	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, false);

	auto ped = CREATE_RANDOM_PED(playerPos.x, playerPos.y, playerPos.z);
	if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
	{
		SET_PED_INTO_VEHICLE(ped, GET_VEHICLE_PED_IS_IN(playerPed, false), -2);
	}

	SET_PED_RELATIONSHIP_GROUP_HASH(ped, relationshipGroup);

	SET_PED_COMBAT_ATTRIBUTES(ped, 5, true);
	SET_PED_COMBAT_ATTRIBUTES(ped, 46, true);

	GIVE_WEAPON_TO_PED(ped, GET_SELECTED_PED_WEAPON(playerPed), 9999, true, true);

	SET_PED_ACCURACY(ped, 100);
	SET_PED_FIRING_PATTERN(ped, 0xC6EE6B4C);
}

static RegisterEffect registerEffect(EFFECT_SPAWN_RANDOM_HOSTILE, OnStart);