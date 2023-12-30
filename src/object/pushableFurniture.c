/**
 * @file pushableFurniture.c
 * @ingroup Objects
 *
 * @brief Pushable Furniture object
 */
#include "functions.h"
#include "object.h"

typedef struct {
    /*0x00*/ Entity base;
    /*0x68*/ u8 unk_68[0x8];
    /*0x70*/ u16 unk_70;
    /*0x72*/ u16 unk_72;
    /*0x74*/ u16 unk_74;
    /*0x76*/ u16 unk_76;
    /*0x78*/ u8 unk_78[0x2];
    /*0x7a*/ u16 unk_7a;
    /*0x7c*/ u16 unk_7c;
    /*0x7e*/ u16 unk_7e;
    /*0x80*/ u8 unk_80;
    /*0x81*/ u8 unk_81;
    /*0x82*/ u8 unk_82;
    /*0x83*/ u8 unk_83;
    /*0x84*/ u8 unk_84[0x2];
    /*0x86*/ u16 unk_86;
} PushableFurnitureEntity;

extern const s16 gUnk_080B4488[];

extern void (*const PushableFurniture_Actions[])(PushableFurnitureEntity*);
extern const u16 gUnk_08121EE4[];
extern const u16 gUnk_08121EF0[];

void sub_08090514(PushableFurnitureEntity*);
void sub_0808FF50(PushableFurnitureEntity*);
void sub_0808FBFC(PushableFurnitureEntity*);
void sub_0808FB68(PushableFurnitureEntity*);
bool32 sub_0808FECC(PushableFurnitureEntity*);
void sub_0808FF20(PushableFurnitureEntity*);
void nullsub_1(PushableFurnitureEntity*);
void sub_0808FD44(PushableFurnitureEntity*, u32);
void sub_0808FDE8(PushableFurnitureEntity*);
bool32 sub_0808FC5C(PushableFurnitureEntity*);
void sub_08090498(PushableFurnitureEntity*);
void sub_08090254(PushableFurnitureEntity*);
void sub_08090094(PushableFurnitureEntity*, u32, u32);
void sub_0809028C(PushableFurnitureEntity*, u32);
void sub_08090480(u32, u32);

void PushableFurniture(PushableFurnitureEntity* this) {
    PushableFurniture_Actions[super->action](this);
    if (super->action != 0) {
        sub_08090514(this);
    }
}

void PushableFurniture_Init(PushableFurnitureEntity* this) {
    bool32 condition;

    super->action = 1;
    super->speed = 0x80;
    super->subtimer = super->timer;
    super->timer = 0;
    super->updatePriority = 3;
    this->unk_81 = 0;
    this->unk_83 = 0;
    super->spriteRendering.b3 = 2;
    if (super->type == 1) {
        super->spritePriority.b0 = 4;
        this->unk_80 = 0;
    } else {
        this->unk_80 = 1;
        super->spritePriority.b0 = 5;
        if ((super->type == 2) || (super->type == 4)) {
            super->y.HALF.HI += 2;
            super->spriteOffsetY = -2;
            super->subAction = 0;
            super->frameIndex = 0;
        }
    }

    if (super->subtimer != 0) {
        condition = FALSE;
        switch (super->subtimer) {
            default:
                if (super->type == 1 && super->type2 == 1) {
                    this->unk_7e = (s8)super->subtimer + super->y.HALF_U.HI;
                } else {
                    this->unk_7e = (s8)super->subtimer + super->x.HALF_U.HI;
                }
                if (super->parent == NULL) {
                    if (CheckFlags(this->unk_86)) {
                        condition++;
                    }
                } else {
                    if ((this->unk_82 & 0x80) != 0) {
                        if (super->parent->action == 2) {
                            condition++;
                        }
                        break;
                    }
                    if (CheckLocalFlag((u32)this->unk_82)) {
                        condition++;
                    }
                }

                break;
            case 0x80:
                condition = TRUE;
                if (super->type == 1 && super->type2 == 1) {
                    this->unk_7e = super->y.HALF.HI;
                } else {
                    this->unk_7e = super->x.HALF.HI;
                }
                break;
        }

        if (condition) {
            this->unk_81 = 1;
            if (super->type == 1 && super->type2 == 1) {
                super->y.HALF.HI = this->unk_7e;
            } else {
                super->x.HALF.HI = this->unk_7e;
            }
        }
    }
    sub_0808FF50(this);
}

void PushableFurniture_Action1(PushableFurnitureEntity* this) {
    if (this->unk_81 == 0) {
        if (this->unk_80 == 0) {
            sub_0808FBFC(this);
        } else {
            sub_0808FB68(this);
        }
    } else {
        if (super->timer != 0 && --super->timer == 0) {
            EnqueueSFX(SFX_BUTTON_PRESS);
        }
    }
    switch (super->type) {
        case 2:
        case 4:
            switch (super->subAction) {
                case 0:
                    if (sub_0808FECC(this)) {
                        super->subAction = 1;
                        super->timer = 12;
                    }
                    break;
                case 1:
                    if (--super->timer == 0) {
                        super->frameIndex = 1;
                        super->subAction = 2;
                        EnqueueSFX(SFX_80);
                        sub_0808FF20(this);
                    }
                    break;
                case 2:
                    nullsub_1(this);
                    break;
            }
    }
}

void sub_0808FB68(PushableFurnitureEntity* this) {
    u32 tileIndex = GetTileIndex(this->unk_70, super->collisionLayer);
    switch (tileIndex) {
        case 0x4030:
        case 0x4031:
            super->action = 2;
            super->direction = (((tileIndex - 0x30) & 1) << 4) | 8;
            SetPlayerControl(CONTROL_1);
            sub_0808FD44(this, 0);
            break;
        default:
            tileIndex = GetTileIndex(this->unk_72, super->collisionLayer);
            switch (tileIndex) {
                case 0x4030:
                case 0x4031:
                    super->action = 2;
                    super->direction = (((tileIndex - 0x30) & 1) << 4) | 8;
                    SetPlayerControl(CONTROL_1);
                    sub_0808FD44(this, 1);
                    break;
            }
            sub_0808FDE8(this);
            break;
    }
}

void sub_0808FBFC(PushableFurnitureEntity* this) {
    u32 tileIndex = GetTileIndex(this->unk_7c, super->collisionLayer);
    if (tileIndex != 0x404a) {
        super->action = 2;
        super->direction = ((tileIndex - 0x4bU) & 3) << 3;
        SetPlayerControl(CONTROL_1);
        sub_0808FD44(this, 0);
    }
}

void PushableFurniture_Action2(PushableFurnitureEntity* this) {
    sub_0800445C(super);
    if (sub_0808FC5C(this)) {
        super->action = 1;
        SetPlayerControl(CONTROL_ENABLED);
    }
}

bool32 sub_0808FC5C(PushableFurnitureEntity* this) {
    bool32 bVar2;
    u8* puVar5;

    LinearMoveUpdate(super);
    if (--super->timer == 0) {
        if ((super->type == 2) || (super->type == 4)) {
            super->spriteOffsetY = 0xfe;
        } else {
            super->spriteOffsetY = 0;
        }
        if (sub_080B1B0C(super)) {
            return 0;
        }
        if (super->subtimer == 0) {
            sub_0808FF50(this);
            return TRUE;
        }
        bVar2 = FALSE;
        if (*(u16*)&super->type == 0x101) {
            if (super->y.HALF.HI == this->unk_7e) {
                bVar2 = TRUE;
            }
        } else {
            if (super->x.HALF.HI == this->unk_7e) {
                bVar2 = TRUE;
            }
        }

        if (!bVar2) {
            sub_0808FF50(this);
            return TRUE;
        }

        this->unk_81 = 1;
        if (super->parent == NULL) {
            SetFlag((u32)this->unk_86);
        } else {
            if ((this->unk_82 & 0x80) != 0) {
                puVar5 = super->parent->spriteAnimation + 2;
                *puVar5 = (1 << (this->unk_7a)) | *puVar5;
            } else {
                SetLocalFlag((u32)this->unk_82);
            }
        }
        if (this->unk_80 == 0) {
            super->timer = 4;
        } else {
            super->timer = 24;
        }
        if ((gPlayerState.flags & PL_MINISH) == 0) {
            super->timer += 16;
        }
        sub_0808FF50(this);
        return TRUE;
    } else {
        return FALSE;
    }
}

void sub_0808FD44(PushableFurnitureEntity* this, u32 param_2) {
    u32 tmp;

    if (this->unk_80 == 1) {
        if (this->unk_83 != 0) {
            sub_08090498(this);
        }
        if (param_2 != 0) {
            tmp = this->unk_72;
        } else {
            tmp = this->unk_70;
        }
        if ((gPlayerState.flags & PL_MINISH) != 0) {
            super->speed = 0x40;
            super->timer = 32;
        } else {
            super->speed = 0x80;
            super->timer = 16;
        }
    } else {
        tmp = this->unk_7c;
        if ((gPlayerState.flags & PL_MINISH) != 0) {
            super->speed = 0x40;
            super->timer = 64;
        } else {
            super->speed = 0x80;
            super->timer = 32;
        }
    }
    EnqueueSFX(SFX_10F);
    sub_08090254(this);
    GetTileIndex(tmp + gUnk_080B4488[super->direction >> 3], super->collisionLayer);
}

void sub_0808FDE8(PushableFurnitureEntity* this) {
    u32 uVar1;
    s32 iVar2;
    u32 uVar3;

    uVar3 = (u32)this->unk_70;
    uVar1 = sub_080B1B44(uVar3 - 1, 1);
    iVar2 = GetTileIndex(uVar3, 1);
    if (iVar2 == 0x402e) {
        if ((((uVar1 & 0xf0) != 0) && ((uVar1 & 0xf0) != 0x50)) || ((uVar1 & 5) == 0)) {
            SetTile(0x402c, uVar3, 1);
        }
    } else {
        iVar2 = sub_080B1B44(uVar3, 1);
        if ((iVar2 == 5) && ((((uVar1 & 0xf0) == 0 || ((uVar1 & 0xf0) == 0x50)) && ((uVar1 & 5) != 0)))) {
            SetTile(0x402e, uVar3, 1);
        }
    }
    uVar3 = (u32)this->unk_72;
    uVar1 = sub_080B1B44(uVar3 + 1, 1);
    iVar2 = GetTileIndex(uVar3, 1);
    if (iVar2 == 0x402f) {
        if ((((uVar1 & 0xf0) != 0) && ((uVar1 & 0xf0) != 0x50)) || ((uVar1 & 10) == 0)) {
            SetTile(0x402d, uVar3, 1);
        }
    } else {
        iVar2 = sub_080B1B44(uVar3, 1);
        if (((iVar2 == 10) && (((uVar1 & 0xf0) == 0 || ((uVar1 & 0xf0) == 0x50)))) && ((uVar1 & 10) != 0)) {
            SetTile(0x402f, uVar3, 1);
        }
    }
}

bool32 sub_0808FECC(PushableFurnitureEntity* this) {
    bool32 result = TRUE;

    if (!((gPlayerState.flags & PL_MINISH) == 0 && (gPlayerEntity.action == PLAYER_BOUNCE) &&
          (gPlayerEntity.animationState == 0) && (gPlayerEntity.y.HALF.HI - super->y.HALF.HI < 0x14) &&
          (super->x.HALF.HI + 0xc > gPlayerEntity.x.HALF.HI) && (super->x.HALF.HI - 12 < gPlayerEntity.x.HALF.HI))) {
        result = FALSE;
    }
    return result;
}

void sub_0808FF20(PushableFurnitureEntity* this) {
    Entity* obj;
    switch (super->type2) {
        case 0:
            break;
        case 1:
        case 2:
            obj = CreateObject(OBJECT_63, super->type2 - 1, 0);
            if (obj != NULL) {
                obj->parent = super;
                CopyPosition(super, obj);
            }
            break;
    }
}

void nullsub_1(PushableFurnitureEntity* this) {
}

void sub_0808FF50(PushableFurnitureEntity* this) {
    u32 tmp;
    u32 position;
    u32 tmp2;
    this->unk_7c = COORD_TO_TILE(super);
    tmp2 = super->x.HALF.HI & 0xf;
    tmp = this->unk_7c;
    position = tmp;
    switch (this->unk_80) {
        case 0:
            this->unk_70 = tmp;
            this->unk_74 = GetTileIndex(this->unk_70, 1);
            SetTile(0x404a, tmp, 1);
            break;
        case 1:
            if ((tmp2 & 8) != 0) {
                this->unk_70 = this->unk_7c;
                this->unk_74 = GetTileIndex(this->unk_70, 1);
                SetTile(gUnk_08121EE4[this->unk_81], position, 1);
                this->unk_72 = tmp + 1;
                this->unk_76 = GetTileIndex(this->unk_72, 1);
                sub_08090094(this, gUnk_08121EE4[this->unk_81 + 4], this->unk_72);
                sub_0809028C(this, 1);
            } else {
                this->unk_72 = this->unk_7c;
                this->unk_76 = GetTileIndex(this->unk_72, 1);
                SetTile(gUnk_08121EE4[this->unk_81], position, 1);
                this->unk_70 = tmp - 1;
                this->unk_74 = GetTileIndex(this->unk_70, 1);
                sub_08090094(this, gUnk_08121EE4[this->unk_81 + 2], this->unk_70);
                sub_0809028C(this, 0);
            }
            break;
    }
}

void sub_08090094(PushableFurnitureEntity* this, u32 param_2, u32 tilePos) {
    FORCE_REGISTER(u32 tmp1, r4);

    u32 index;
    u32 tmp2;

    tmp1 = sub_080B1B44(tilePos, 1);
    index = GetTileIndex(tilePos, 1);
    if ((index & 0x4000) == 0) {
        index = param_2;
        switch (index) {
            case 0x4025:
                if (tmp1 == 5) {
                    index = 0x4022;
                }
                SetTile(index, tilePos, 1);
                return;
            case 0x402d:
            case 0x402f:
                if (tmp1 == 5) {
                    index = 0x4022;
                }
                SetTile(index, tilePos, 1);
                return;
            case 0x4024:
            case 0x402c:
            case 0x402e:
                if (tmp1 == 10) {
                    index = 0x4022;
                }
                SetTile(index, tilePos, 1);
                return;
            default:
                SetTile(index, tilePos, 1);
                return;
        }
    }
    switch (index) {
        case 0x4022:
        default:
            return;
        case 0x4025:
            if (param_2 == 0x4024) {
                index = 0x4022;
                this->unk_83 |= 0x10;
            }
            if (param_2 == 0x402c) {
                index = 0x4022;
                this->unk_83 |= 0x10;
            }
            break;
        case 0x402d:
        case 0x402f:
            if (param_2 == 0x402c) {
                index = 0x402b;
                this->unk_83 |= 0x10;
            }
            if (param_2 == 0x4024) {
                index = 0x4022;
                this->unk_83 |= 0x10;
            }
            break;
        case 0x4024:
            if (param_2 == 0x4025) {
                index = 0x4022;
                this->unk_83 |= 0x20;
            }
            if (param_2 == 0x402d) {
                index = 0x4022;
                this->unk_83 |= 0x20;
            }
            break;
        case 0x402c:
        case 0x402e:
            if (param_2 == 0x402d) {
                index = 0x402b;
                this->unk_83 |= 0x20;
            }
            if (param_2 == 0x4025) {
                index = 0x4022;
                this->unk_83 |= 0x20;
            }
            break;
    }

    SetTile(index, tilePos, 1);
}

void sub_08090254(PushableFurnitureEntity* this) {
    sub_0807B9B8(this->unk_74, this->unk_70, super->collisionLayer);
    if (this->unk_80 == 1) {
        sub_0807B9B8(this->unk_76, this->unk_72, super->collisionLayer);
    }
}

void sub_0809028C(PushableFurnitureEntity* this, u32 param_2) {
    u32 uVar2;
    u32 pos;

    this->unk_83 &= 0x30;
    pos = this->unk_70 - 0x80;
    uVar2 = this->unk_72 - 0x80;
    if (param_2 == 1) {
        if ((this->unk_83 & 0x20) != 0) {
            sub_08090480(0, uVar2 + 1);
        } else {
            switch (GetTileType(uVar2, 2)) {
                case 0x301:
                    this->unk_83 |= 8;
                    break;
                case 0x308:
                    this->unk_83 |= 2;
                    break;
            }
        }
        if ((this->unk_83 & 0x2a) != 0) {
            sub_08090480(0, pos);
            sub_08090480(0, uVar2);
        }
        if ((this->unk_83 & 0x10) != 0) {
            switch (GetTileType(pos - 1, 1)) {
                case 0x300:
                    break;
                default:
                    sub_08090480(0, pos - 1);
                    sub_08090480(2, pos - 2);
                    break;
            }
            return;
        }
        switch (GetTileType(pos - 1, 2)) {
            case 0x300:
                this->unk_83 |= 4;
                break;
            case 0x308:
                this->unk_83 |= 1;
                break;
        }

        if (((this->unk_83 & 0x15) != 0) && ((this->unk_83 & 0x2a) == 0)) {
            sub_08090480(0, pos);
            sub_08090480(1, uVar2);
        }
    } else {
        if ((this->unk_83 & 0x10) != 0) {
            sub_08090480(0, pos - 1);
        } else {
            switch (GetTileType(pos, 2)) {
                case 0x302:
                    this->unk_83 |= 4;
                    break;
                case 0x306:
                    this->unk_83 |= 1;
                    break;
            }
        }
        if ((this->unk_83 & 0x15) != 0) {
            sub_08090480(0, pos);
            sub_08090480(0, uVar2);
        }
        if ((this->unk_83 & 0x20) != 0) {
            switch (GetTileType(uVar2 + 1, 1)) {
                case 0x300:
                    break;
                default:
                    sub_08090480(0, uVar2 + 1);
                    sub_08090480(1, uVar2 + 2);
                    break;
            }
            return;
        }
        switch (GetTileType(uVar2 + 1, 2)) {
            case 0x300:
                this->unk_83 |= 8;
                break;
            case 0x306:
                this->unk_83 |= 2;
                break;
        }
        if ((this->unk_83 & 0x2a) != 0 && (this->unk_83 & 0x15) == 0) {
            sub_08090480(2, pos);
            sub_08090480(0, uVar2);
        }
    }
}

void sub_08090480(u32 param_1, u32 param_2) {
    SetTile(gUnk_08121EF0[param_1], param_2, 1);
}

void sub_08090498(PushableFurnitureEntity* this) {
    u32 tmp = this->unk_70 - 0x80;
    RestorePrevTileEntity(tmp, 1);
    if (((this->unk_83 & 1) != 0) && (GetTileType(tmp, 2) == 0x306)) {
        sub_08000148(0x62, tmp, 1);
    }
    tmp = this->unk_72 - 0x80;
    RestorePrevTileEntity(tmp, 1);
    if (((this->unk_83 & 2) != 0) && (GetTileType(tmp, 2) == 0x308)) {
        sub_08000148(99, tmp, 1);
    }
}

void sub_08090514(PushableFurnitureEntity* this) {
    if (super->parent != NULL) {
        switch (super->parent->subAction) {
            case 0:
                super->spriteRendering.b3 = 2;
                super->spritePriority.b0 = 4;
                break;
            case 1:
                super->spriteRendering.b3 = 3;
                super->spritePriority.b0 = 4;
                break;
            case 2:
                super->spriteRendering.b3 = 2;
                super->spritePriority.b0 = 5;
                break;
            case 3:
                super->spriteRendering.b3 = 2;
                super->spritePriority.b0 = 3;
                break;
        }
    }
}

void (*const PushableFurniture_Actions[])(PushableFurnitureEntity*) = {
    PushableFurniture_Init,
    PushableFurniture_Action1,
    PushableFurniture_Action2,
};
const u16 gUnk_08121EE4[] = {
    0x402b, 0x4022, 0x402c, 0x4024, 0x402d, 0x4025,
};
const u16 gUnk_08121EF0[] = {
    0x4026,
    0x4065,
    0x4066,
    0,
};
