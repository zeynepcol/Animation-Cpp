#include <windows.h>
#include "icb_gui.h"

int F1, F2;
ICBYTES Background, Buttercup, Blossom, Bubbles, Mojo, Cloud, LightEffect, Explosion, MojoDies, Bushes;
ICBYTES ButtercupRun[18], BlossomRun[18], BubblesRun[18], MojoRun[30], CloudRun[6], ExplosionFrames[6], MojoDiesFrames[3], BushesFrames[4];

void ICGUI_Create() {
    ICG_MWSize(1200, 830);
    ICG_MWTitle("POWERPUFF GIRLS");
}

void LoadCharacter(ICBYTES& character, ICBYTES characterRun[], int coordinates[][4]) {
    for (int i = 0; i < 18; i++) {
        Copy(character, coordinates[i][0], coordinates[i][1], coordinates[i][2], coordinates[i][3], characterRun[i]);
    }
}

void LoadCloudRun() {
    if (!ReadImage("cloud.bmp", Cloud)) {
        MessageBox(NULL, "cloud.bmp not found!", "Error", MB_OK);
        return;
    }
    int cloudCoords[6][4] = {
        {15, 31, 94, 36}, {116, 21, 99, 36}, {10, 102, 100, 24},
        {119, 83, 89, 43}, {10, 167, 97, 31}, {128, 172, 83, 28}
    };
    for (int i = 0; i < 6; i++) {
        Copy(Cloud, cloudCoords[i][0], cloudCoords[i][1], cloudCoords[i][2], cloudCoords[i][3], CloudRun[i]);
    }
}

void LoadMojoRun() {
    if (!ReadImage("mojo.bmp", Mojo)) {
        MessageBox(NULL, "mojo.bmp not found!", "Error", MB_OK);
        return;
    }
    int mojoCoords[30][4] = {
        {32, 6, 109, 61}, {155, 6, 123, 62}, {289, 1, 133, 67}, {451, 5, 110, 57},
        {37, 98, 110, 57}, {155, 93, 123, 62}, {288, 96, 133, 67}, {457, 99, 109, 61},
        {29, 195, 164, 57}, {209, 195, 182, 56}, {415, 197, 124, 54}, {11, 285, 164, 57},
        {184, 284, 182, 56}, {412, 284, 124, 54}, {37, 370, 97, 58}, {173, 368, 97, 56},
        {315, 369, 107, 55}, {464, 366, 109, 56}, {40, 450, 97, 58}, {175, 452, 97, 56},
        {315, 450, 107, 55}, {466, 452, 109, 56}, {31, 548, 113, 57}, {169, 541, 153, 64},
        {345, 546, 98, 58}, {463, 545, 110, 62}, {29, 641, 113, 57}, {165, 634, 153, 63},
        {350, 639, 98, 58}, {465, 637, 110, 62}
    };
    for (int i = 0; i < 30; i++) {
        Copy(Mojo, mojoCoords[i][0], mojoCoords[i][1], mojoCoords[i][2], mojoCoords[i][3], MojoRun[i]);
    }

    if (!ReadImage("mojolost.bmp", MojoDies)) {
        MessageBox(NULL, "mojodies.bmp not found!", "Error", MB_OK);
        return;
    }
    int mojoDiesCoords[3][4] = {
        {23, 17, 93, 77},
        {164, 17, 100, 77},
        {312, 7, 127, 96}
    };
    for (int i = 0; i < 3; i++) {
        Copy(MojoDies, mojoDiesCoords[i][0], mojoDiesCoords[i][1], mojoDiesCoords[i][2], mojoDiesCoords[i][3], MojoDiesFrames[i]);
    }
}

void LoadAgentRun() {
    if (!ReadImage("Buttercup182.bmp", Buttercup)) {
        MessageBox(NULL, "Buttercup182.bmp not found!", "Error", MB_OK);
        return;
    }
    if (!ReadImage("Blossom182.bmp", Blossom)) {
        MessageBox(NULL, "Blossom182.bmp not found!", "Error", MB_OK);
        return;
    }
    if (!ReadImage("Bubbles182.bmp", Bubbles)) {
        MessageBox(NULL, "Bubbles182.bmp not found!", "Error", MB_OK);
        return;
    }

    int buttercupCoords[18][4] = {
        {11, 17, 31, 42}, {73, 17, 34, 42}, {133, 17, 34, 42}, {193, 16, 31, 43},
        {254, 15, 33, 44}, {315, 15, 34, 44}, {376, 14, 34, 45}, {435, 16, 35, 43},
        {497, 16, 34, 43}, {9, 76, 35, 44}, {74, 75, 36, 44}, {131, 79, 39, 40},
        {192, 77, 33, 42}, {255, 74, 36, 45}, {309, 73, 37, 46}, {368, 74, 39, 45},
        {432, 75, 35, 44}, {493, 76, 38, 43}
    };

    int blossomCoords[18][4] = {
        {15, 9, 27, 50}, {73, 9, 33, 50}, {135, 8, 30, 51}, {195, 8, 30, 51},
        {251, 9, 33, 50}, {314, 6, 33, 53}, {374, 5, 34, 54}, {434, 6, 32, 53},
        {495, 6, 32, 53}, {15, 67, 31, 52}, {74, 67, 30, 52}, {131, 69, 37, 50},
        {191, 77, 34, 42}, {255, 72, 34, 47}, {314, 63, 33, 56}, {370, 65, 38, 54},
        {431, 63, 33, 56}, {491, 65, 35, 54}
    };

    int bubblesCoords[18][4] = {
        {11, 17, 32, 42}, {74, 17, 35, 42}, {134, 16, 34, 43}, {191, 16, 33, 43},
        {256, 16, 33, 43}, {315, 15, 35, 44}, {376, 14, 35, 45}, {435, 15, 35, 44},
        {495, 16, 33, 43}, {11, 75, 35, 44}, {73, 74, 34, 45}, {132, 78, 38, 41},
        {191, 77, 34, 42}, {256, 73, 36, 46}, {311, 73, 35, 46}, {367, 75, 38, 44},
        {432, 74, 37, 45}, {491, 76, 37, 43}
    };

    LoadCharacter(Buttercup, ButtercupRun, buttercupCoords);
    LoadCharacter(Blossom, BlossomRun, blossomCoords);
    LoadCharacter(Bubbles, BubblesRun, bubblesCoords);
}

void LoadBushes() {
    if (!ReadImage("bushes.bmp", Bushes)) {
        MessageBox(NULL, "bushes.bmp not found!", "Error", MB_OK);
        return;
    }
    int bushesCoords[4][4] = {
        {24, 14, 118, 66},
        {179, 12, 118, 66},
        {22, 92, 118, 66},
        {177, 90, 118, 66}
    };
    for (int i = 0; i < 4; i++) {
        Copy(Bushes, bushesCoords[i][0], bushesCoords[i][1], bushesCoords[i][2], bushesCoords[i][3], BushesFrames[i]);
    }
}

void LoadExplosion() {
    if (!ReadImage("explosion.bmp", Explosion)) {
        MessageBox(NULL, "explosion.bmp not found!", "Error", MB_OK);
        return;
    }
    int explosionCoords[6][4] = {
        {43, 67, 124, 131},
        {224, 50, 155, 165},
        {425, 48, 168, 169},
        {32, 285, 154, 151},
        {232, 291, 142, 141},
        {434, 290, 142, 139}
    };
    for (int i = 0; i < 6; i++) {
        Copy(Explosion, explosionCoords[i][0], explosionCoords[i][1], explosionCoords[i][2], explosionCoords[i][3], ExplosionFrames[i]);
    }
}

void ShowLightEffect() {
    if (!ReadImage("girls.bmp", LightEffect)) {
        MessageBox(NULL, "girls.bmp not found!", "Error", MB_OK);
        return;
    }
    int startY = 400;
    for (int i = 0; i < 20; i++) {
        ReadImage("white.bmp", Background);
        PasteNon0(LightEffect, 400, startY - i * 10, Background);
        DisplayImage(F1, Background);
        Sleep(60);
    }
}

void AnimateBushes() {
    static int bushFrame = 0;
    static int bushXOffset = 0;    
    int bushY = 500;               
    int bushSpacing = 150;         
    int numBushes = 6;             

    bushXOffset = (bushFrame % 2 == 0) ? bushXOffset + 3 : bushXOffset - 3;

    for (int i = 0; i < numBushes; i++) {
        int bushX = 50 + i * bushSpacing + bushXOffset;
        PasteNon0(BushesFrames[bushFrame % 4], bushX, bushY, Background);
    }

    bushFrame = (bushFrame + 1) % 4;

    DisplayImage(F1, Background);
}

void AnimateCloud() {
    static int cloudFrame = 0;
    static int cloudX = 0;  
    int cloudY = 50;        

    ReadImage("white.bmp", Background);

    PasteNon0(CloudRun[cloudFrame % 6], cloudX, cloudY, Background);

    cloudFrame = (cloudFrame + 1) % 6;   
    cloudX += 30;                         

    if (cloudX > 1200) {
        cloudX = -100;  
    }

    DisplayImage(F1, Background);
    
}

void ShowMojoDies(int x, int y) {
    for (int i = 0; i < 3; i++) {
        ReadImage("white.bmp", Background);  
        AnimateCloud();                    
        AnimateBushes();

        PasteNon0(MojoDiesFrames[i], x, y, Background);
        DisplayImage(F1, Background);
        Sleep(100); 
    }
}

void ShowExplosion(int x, int y) {

    ShowMojoDies(x, y);

    for (int i = 0; i < 6; i++) {
        ReadImage("white.bmp", Background);  
        AnimateCloud();                        
        AnimateBushes();

        PasteNon0(ExplosionFrames[i], x, y, Background);
        DisplayImage(F1, Background);
        Sleep(60);
    }
}

void AnimateCharacterToMojo(ICBYTES characterRun[], int xStart, int yStart, int mojoX, int mojoY) {
    int x = xStart, y = yStart;
    int dx = (mojoX - x) / 18, dy = (mojoY - y) / 18; 

    for (int i = 0; i < 18; i++) {
        ReadImage("white.bmp", Background);

        AnimateCloud();
        AnimateBushes();

        PasteNon0(MojoRun[i % 30], mojoX, mojoY, Background);

        PasteNon0(characterRun[i], x, y, Background);
        DisplayImage(F1, Background);
        Sleep(60);

        x += dx;
        y += dy;
    }


    for (int i = 0; i < 5; i++) { 
        ReadImage("white.bmp", Background);

        AnimateCloud();
        AnimateBushes();

        PasteNon0(MojoRun[17 % 30], mojoX, mojoY, Background);  

        PasteNon0(characterRun[17 - i], x - dx * i, y - dy * i, Background); 
        DisplayImage(F1, Background);
        Sleep(60);
    }
}

void PowerpuffAttackMojo() {
    int mojoX = 500, mojoY = 200;

    int buttercupXStart = 0, buttercupYStart = 300;
    int blossomXStart = 0, blossomYStart = 350;
    int bubblesXStart = 0, bubblesYStart = 400;

    AnimateCharacterToMojo(ButtercupRun, buttercupXStart, buttercupYStart, mojoX, mojoY);
    AnimateCharacterToMojo(BlossomRun, blossomXStart, blossomYStart, mojoX, mojoY);
    AnimateCharacterToMojo(BubblesRun, bubblesXStart, bubblesYStart, mojoX, mojoY);

    ShowExplosion(mojoX, mojoY);
}

void MakePowerpuffMagic() { 
    PowerpuffAttackMojo();
    ShowLightEffect();
}

void ICGUI_main() {
    F1 = ICG_FrameThin(5, 140, 450, 430);
    
    LoadAgentRun();
    LoadMojoRun();
    LoadCloudRun();
    LoadExplosion();
    LoadBushes();
    ICG_Button(400, 5, 160, 55, "Start\n --------------------\n Animation", MakePowerpuffMagic);
    ReadImage("white.bmp", Background);
    DisplayImage(F1, Background);
}
