#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gBattleAnimBankAttacker;
extern u8 gBattleAnimBankTarget;

static void sub_80CDE78(struct Sprite* sprite);
static void sub_80CDEB0(struct Sprite* sprite);
static void sub_80CDEC0(struct Sprite* sprite);

// slash (a cutting animation)
// Used in Slash and False Swipe.

void sub_80CDD74(struct Sprite* sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimBankAttacker, 2) + gBattleAnimArgs[1];
        sprite->pos1.y = sub_8077ABC(gBattleAnimBankAttacker, 3) + gBattleAnimArgs[2];
    }
    else
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimBankTarget, 2) + gBattleAnimArgs[1];
        sprite->pos1.y = sub_8077ABC(gBattleAnimBankTarget, 3) + gBattleAnimArgs[2];
    }

    sprite->data[0] = 0;
    sprite->data[1] = 0;
    StoreSpriteCallbackInData(sprite, sub_80CDEC0);
    sprite->callback = sub_8078600;
}

void sub_80CDDDC(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimBankTarget, 2) + 0xFFD0;
    sprite->pos1.y = sub_8077ABC(gBattleAnimBankTarget, 3);
    StoreSpriteCallbackInData(sprite, sub_80CDE78);
    sprite->callback = sub_8078600;
}

void sub_80CDE24(struct Sprite* sprite)
{
    sprite->pos1.x = sprite->pos1.x = sub_8077ABC(gBattleAnimBankTarget, 2) + 0xFFD0 + gBattleAnimArgs[0];
    sprite->pos1.y = sub_8077ABC(gBattleAnimBankTarget, 3);
    StartSpriteAnim(sprite, 1);
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->callback = sub_80CDEC0;
}

void sub_80CDE78(struct Sprite* sprite)
{
    if (++sprite->data[0] > 8)
    {
        sprite->data[0] = 12;
        sprite->data[1] = 8;
        sprite->data[2] = 0;
        StoreSpriteCallbackInData(sprite, sub_80CDEB0);
        sprite->callback = sub_8078364;
    }
}

void sub_80CDEB0(struct Sprite* sprite)
{
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->callback = sub_80CDEC0;
}

void sub_80CDEC0(struct Sprite* sprite)
{
    if (++sprite->data[0] > 1)
    {
        sprite->data[0] = 0;
        sprite->invisible = !sprite->invisible;
        if (++sprite->data[1] > 8)
            move_anim_8072740(sprite);
    }
}
