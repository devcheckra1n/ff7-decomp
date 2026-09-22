//! PSYQ=4.0 CC1=2.7.2

#include "common.h"
#include "game.h"
#include "libgte.h"

typedef struct {
    u32 unk0;
    u32 unk4;
} UnkRectData;

typedef struct {
    /* 0x00 */ u8 unk0[8];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ u8 unkA[6];
} ChocoboEntry; // size: 0x10

typedef struct {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ u8 unk2[8];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 unkC[8];
} ChocoboUnk14; // size: 0x14

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 unkC[0x2C];
    /* 0x38 */ ChocoboUnk14* unk38;
    /* 0x3C */ u8 unk3C[4];
    /* 0x40 */ ChocoboEntry* entries;
} ChocoboRace;

typedef struct {
    /* 0x00 */ u8 unk0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 unk8[0x1C];
} ChocoboUnk24; // size: 0x24

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ ChocoboUnk24* unk4;
} ChocoboUnk1254;

typedef struct {
    /* 0x00 */ u8 unk0[4];
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6[0x78];
    /* 0x7E */ s16 unk7E;
    /* 0x80 */ u8 unk80[0x10];
    /* 0x90 */ s16 unk90;
    /* 0x92 */ s16 unk92;
    /* 0x94 */ s16 unk94;
    /* 0x96 */ u8 unk96[0xE];
} ChocoboRacer; // size: 0xA4

extern UnkRectData D_800A0020;
extern UnkRectData D_800A0028;
extern VECTOR D_800A0068;
extern ChocoboUnk1254* D_800B1254;
extern s32 D_800B1358;
extern u16 D_800B26CC[];
extern s32 D_800B7478;
extern s32 D_800B747C;
extern s32 D_800B74F8;
extern s32 D_800B74FC;
extern s32 D_800B7500;
extern s32 D_800B7514;
extern s32 D_800B7538;
extern s32 D_800B753C;
extern s32 D_800B7598;
extern s32 D_800B7594;
extern s32 D_800B759C;
extern ChocoboRacer D_800B75CC[6];
extern s32 D_800B7A48;
extern s32 D_800B7A64;
extern s16 D_800F5028;
extern s32 D_800F5034;
extern s32 D_800F5040;
extern s32 D_800F5044;
extern s32 D_800F5048;
extern s32 D_800F504C;
extern s32 D_800F5050;
extern ChocoboUnk14 D_800F5054;
extern s32 D_800F5070;
extern s32 D_800F507C;
extern ChocoboRace* D_800F5084;
extern s32 D_800F5088;
extern s32 D_800F508C;
extern s32 D_800F5098;
extern s16 D_800F509C;
extern s32 D_800F5124;

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", MINI_Chocobo);

static void func_800A1260(void) {
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;

    temp_s0 = D_800F5084->unk0;
    temp_s2 = (D_800B7598 + temp_s0) % temp_s0;
    temp_s1 = (D_800F507C + temp_s0) % temp_s0;

    PushMatrix();

    if (temp_s1 < temp_s2) {
        func_800A1354(0, temp_s1);
        func_800A1354(temp_s2, temp_s0);
    } else {
        func_800A1354(temp_s2, temp_s1);
    }

    PopMatrix();
}

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A1354);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A157C);

void ChocoboRaceInit(void) {
    u32 pad;

    D_800F5084 = (ChocoboRace*)0x80110000;
    D_800B7514 = 255;
    D_800F5070 = -16;
    D_800B759C = -1;
    D_800B74FC = ((ChocoboRace*)0x80110000)->unk0;
    D_800B7478 = 0;
    D_800B7500 = ((ChocoboRace*)0x80110000)->unk8;
    D_800B747C = (Savemap.memory_bank_1[0] + (Savemap.memory_bank_1[1] << 8)) >= 1000 ? -1 : 0;
    pad = InputReadPadsRaw() >> 16;
    if ((pad & 0xF0) == 0xF0) {
        if (pad & 8) {
            Savemap.memory_bank_3[6] = 1;
        }
        if (pad & 2) {
            Savemap.memory_bank_3[6] = 2;
        }
    }
    if (Savemap.memory_bank_3[8] != 0) {
        Savemap.memory_bank_3[9] = 255;
    }
    D_800B7538 = 0;
    D_800B74F8 = 0;
    D_800B753C = 0;
    D_800F504C = -1;
    D_800F508C = -1;
    D_800F5050 = (D_800F5098 + 3) * 2;
    D_800F5098 = Savemap.memory_bank_3[0x17];
    if (Savemap.memory_bank_3[9] != 0) {
        D_800B7A48 = -1;
    } else {
        D_800B7A48 = 0;
    }
    D_800F5124 = 1;
    D_800F5088 = -1;
    D_800B7594 = -1;
    D_800F5040 = 0;
    D_800F5048 = 0;
    D_800B7A64 = 0;
    D_800F5044 = 0;
    D_800B75CC[0].unk94 = 30;
    D_800B753C = 0;
}

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A17F0);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A18BC);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A1F40);

static void func_800A272C(s32 arg0, s32 arg1) {
    RECT sp10;
    RECT sp18;
    s32 var_a0;
    u32 var_a1;

    sp10 = *(RECT*)&D_800A0020;
    sp18 = *(RECT*)&D_800A0028;

    if (arg0 != 0) {
        SysCdromStartLoadLzs(0x3C1, 0x20000, (u_long*)0x80110000, 0);
    } else {
        SysCdromStartLoadLzs(0x32C, 0x20000, (u_long*)0x80110000, 0);
    }

    while (SystemCdromReadChain() != 0) {
    }

    LoadImage(&sp10, (u_long*)0x80110000);
    DrawSync(0);

    if (arg0 != 0) {
        SysCdromStartLoadLzs(0x3F1, 0x1E000, (u_long*)0x80190000, 0);
    } else {
        SysCdromStartLoadLzs(0x3CE, 0x1E800, (u_long*)0x80190000, 0);
    }

    while (SystemCdromReadChain() != 0) {
    }

    switch (arg1) {
    case 0:
        SysCdromStartLoadLzs(0x459, 0x30000, (u_long*)0x80110000, 0);
        break;
    case 1:
        SysCdromStartLoadLzs(0x433, 0x30000, (u_long*)0x80110000, 0);
        break;
    case 2:
        SysCdromStartLoadLzs(0x417, 0x30000, (u_long*)0x80110000, 0);
        break;
    case 3:
        SysCdromStartLoadLzs(0x49C, 0x30000, (u_long*)0x80110000, 0);
        break;
    }

    while (SystemCdromReadChain() != 0) {
    }

    LoadImage(&sp18, (u_long*)0x80110000);
    DrawSync(0);

    if (arg0 != 0) {
        SysCdromStartLoadLzs(0x33E, 0x6A000, (u_long*)0x80110000, 0);
    } else {
        SysCdromStartLoadLzs(0x293, 0x7D000, (u_long*)0x80110000, 0);
    }

    while (SystemCdromReadChain() != 0) {
    }
}

static void func_800A28D8(void) {
    SysCdromStartLoadLzs(0x4C9, 0x1000U, (u_long*)&D_80077F64[0][0x2000], NULL);
    do {

    } while (SystemCdromReadChain() != 0);
    SysCdromStartLoadLzs(0x4CA, 0x1000U, (u_long*)&D_80077F64[0][0x3000], NULL);
    do {

    } while (SystemCdromReadChain() != 0);
    SysCdromStartLoadLzs(0x4C8, 0x800U, (u_long*)&D_80077F64[1][0xC00], NULL);
    do {

    } while (SystemCdromReadChain() != 0);
    SysCdromStartLoadLzs(0x4C7, 0x800U, (u_long*)&D_80077F64[1][0x1400], NULL);
    do {

    } while (SystemCdromReadChain() != 0);
}

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A2984);

void func_800A2BD4(s32, s32);

static void ChocoboUpdateTrackRange(void) {
    s32 count;
    s32 start;
    s32 end;

    count = D_800F5084->unk0;
    start = (D_800B7598 + count) % count;
    end = (D_800F507C + count) % count;
    D_800F5034 = 0;
    if (end < start) {
        func_800A2BD4(0, end);
        func_800A2BD4(start, count);
    } else {
        func_800A2BD4(start, end);
    }
}

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A2BD4);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A3308);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A34A8);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A44E4);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A4888);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A500C);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A68D4);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A6B9C);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A6E50);

void ChocoboLoadCourseEntry(s16 id, s16 arg1) {
    if (D_800B7A48 == -1) {
        D_800F5054.unk0 = -1;
        D_800F5028 = arg1;
        D_800F509C = id;
        return;
    }
    D_800B1358 = -1;
    if (id != -1) {
        D_800F508C = D_800B753C = arg1;
        D_800F5054 = D_800F5084->unk38[id - 1];
    }
}

void ChocoboLookAt(MATRIX* m, SVECTOR* eye, SVECTOR* at) {
    VECTOR v;
    VECTOR x;
    VECTOR z;
    VECTOR y;

    y = D_800A0068;
    v.vx = at->vx - eye->vx;
    v.vy = at->vy - eye->vy;
    v.vz = at->vz - eye->vz;
    VectorNormal(&v, &z);
    OuterProduct12(&z, &y, &v);
    VectorNormal(&v, &x);
    OuterProduct12(&z, &x, &v);
    VectorNormal(&v, &y);
    m->m[0][0] = x.vx;
    m->m[0][1] = x.vy;
    m->m[0][2] = x.vz;
    m->m[1][0] = y.vx;
    m->m[1][1] = y.vy;
    m->m[1][2] = y.vz;
    m->m[2][0] = z.vx;
    m->m[2][1] = z.vy;
    m->m[2][2] = z.vz;
    ApplyMatrix(m, eye, &v);
    m->t[0] = -v.vx;
    m->t[1] = -v.vy;
    m->t[2] = -v.vz;
}

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A7AB8);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A7CA4);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A869C);

void ChocoboMarkEntry(s16 id) {
    if (id > 128) {
        D_800F5084->entries[id - 128].unk8 = -1;
    } else {
        D_800F5084->entries[id].unk8 = 1;
    }
}

s32 ChocoboCalcAngle(s16 x, s16 sign) {
    s16 i;

    if (x >= 4096) {
        return 1024;
    }
    if (x < -4095) {
        return 3072;
    }
    i = (x + 4096) & 0x1FFF;
    if (sign > 0) {
        return (D_800B26CC[i] + 1024) & 0xFFF;
    }
    return (D_800B26CC[0x2000 - i] + 3072) & 0xFFF;
}

s32 ChocoboCalcAngleToPoint(SVECTOR* from, SVECTOR* to) {
    VECTOR v;
    s16 x;
    s16 z;
    s16 i;

    v.vx = to->vx - from->vx;
    v.vy = to->vy - from->vy;
    v.vz = to->vz - from->vz;
    VectorNormal(&v, &v);
    x = v.vx;
    z = v.vz;
    if (x >= 4096) {
        return 1024;
    }
    if (x < -4095) {
        return 3072;
    }
    i = (x + 4096) & 0x1FFF;
    if (z <= 0) {
        return (D_800B26CC[0x2000 - i] + 3072) & 0xFFF;
    }
    return (D_800B26CC[i] + 1024) & 0xFFF;
}

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A8AE8);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A9828);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A9A94);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800A9D94);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AAC00);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AAF1C);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AB410);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800ABABC);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AC554);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AD52C);

void ChocoboDrawText(const char* str, s32 unused, s32 x, s32 y) { SysMenuDrawString(x, y, str, 7); }

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AD7E8);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AD91C);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AD9D8);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AE534);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AE7D4);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AF11C);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AF9E4);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AFC64);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800AFDBC);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800B00DC);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800B01B0);

INCLUDE_ASM("asm/us/mini/chocobo/nonmatchings/chocobo", func_800B0E7C);
