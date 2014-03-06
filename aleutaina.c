#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#define FALSE 0 //definitions for validating input
#define CORRECT !(FALSE)

 //stat functions

 void playerStat();
 void tonStat();
 void impStat();
 void goblinStat();
 void sorcererStat();
 void minotaurStat();
 void harpyStat();
 void ghoulStat();
 void lycanStat();
 void satyrStat();
 void zomjagStat();
 void felgrinStat();

//global variables

int player[5]={200,50,35,60,30};
    /*character
    array elements are:
    player[0] health
    player[1] magic
    player[2] attack
    player[3] defense
    player[4] evasion
    */
int felgrin[5]={100,60,50,50,22};
int tonberry[5];
int imp[5];
int goblin[5];
int sorcerer[5];
int minotaur[5];
int harpy[5];
int ghoul[5];
int lycan[5];
int satyr[5];
int zomjag[5];

//game system variables

 int commandN;
 char command[100];
 int i=14;
 int j=7;
 int a=0;
 int x,y;
 int win=0;
 int valid;
 int rto7;
 int rseed;
 int potion=0;
 int magicShield=1;
 int sealedDoor=0;
 int magicRing=1;
 int magicCrystal=1;
 int magicSword=1;
 int potionFindOne=1;
 int potionFindTwo=1;
 int potionFindThree=1;
 int arrowTrap=1;
 int arrowTrapLever=1;

 //battle system variables

 int battle = 0;
 int playerTurn = 1;
 int playerDefend = 0;
 int enemyAttack = 0;
 int enemyMagic = 0;
 int randAttack = 0;
 int dmgAmount = 0;
 int monsterNum  = 0;
 char userNum[100];
 int holdNum = 0;
 int fleeRand=0;

//maps

 int world[16][16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       1,4,15,1,1,1,1,1,1,1,1,1,1,16,1,1,
                       1,0,0,0,1,1,1,9,1,1,1,1,1,12,1,1,
                       1,0,0,0,0,1,1,8,1,0,0,0,0,14,13,1,
                       1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                       1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,
                       1,0,1,0,0,0,0,0,0,0,1,5,6,1,0,1,
                       1,0,1,1,0,0,0,0,0,0,1,5,5,1,0,1,
                       1,0,1,11,1,0,0,0,0,0,0,5,5,1,0,1,
                       1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,
                       1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,
                       1,0,1,3,2,2,1,0,0,0,0,0,0,0,0,1,
                       1,0,1,2,2,2,1,0,0,1,1,1,1,0,0,1,
                       1,0,1,1,2,2,1,0,0,1,10,7,1,0,0,1,
                       1,0,0,0,0,0,1,0,0,1,7,7,7,0,0,1,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}; //content map

 int worldMap[16][16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        1,0,0,0,0,0,0,4,0,0,0,0,0,0,0,1,
                        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}; //[player map

    //character
    //assign values to array positions representing character attributes


int main()
{
 rseed = rand();
 srand(rseed);

 printf("\nWelcome to Aleutaina! You will play as Sir Albrecht of Vorum, a renowned knight in the land of Aleutaina.\n");
 getchar();
 printf("\nReturning from his journeys to the wilder places of Aleutaina, Sir Albrecht is\ninformed by messenger hawk");
 printf(" that the Kingdom of Vorum has been stricken with a\nlooming miasma that brings pestilence to the land.\n");
 getchar();
 printf("\Worse yet, the Orb of Light, an ancestral relic of the King and the only source of power keeping the miasma at bay,");
 printf(" has been stolen by the Dark Warlock Felgrin.");
 getchar();
 printf("\nSir Albrecht, with nary a moment's rest upon his return, is tasked with\nretrieving the Orb of Light and putting an end to");
 printf(" Felgrin's villiany! \nGo forth valiant knight!\n\n");
 getchar();
 printf("\nAfter days of searching, Sir Albrecht finally reaches the keep of the Warlock\n");
 printf("Felgrin, Castle Jin'ar. The two goblins standing guard outside prove no match\nfor the stalwart knight.\n");
 printf("\nWith the power of his Holy Smite, Sir Albrecht breaks the evil magic sealing\nthe door.\n");
 getchar();
 printf("\nSir Albrecht enters cautiously, only to find the seal spring up behind him anew!Trapping him within.\n");
 getchar();
 printf("\nWith only his wits and sword-arm, Sir Albrecht begins his search for Felgrin andthe Orb of Light.\n\n");
 getchar();
 //game loop (will continue until win =1)
 while(win!=1){
 /*printf("\nrto=%d \n", rto7); for testing random encounter variable*/

 int playerTurn= 1; //resets player turn counter
 int magicCount= 2; //resets magic usage
 int fleeRand= 0; // resets random flee number

 if (rto7==7 || rto7==3){ //checks for a random encounter
        battle=1;
             }

 if(battle==1){
    srand(time(NULL)); //give me your seed ^_^ (seed rand with time)

    monsterNum = 1 + rand() % 9; //randomizes monster pick

    //battle
    switch(monsterNum){ //chooses which monster to fight

    case(1):
    //tonberry fight
    tonberry[0] = 45; //health
    tonberry[1] = 40; //magic
    tonberry[2] = 50; //attack
    tonberry[3] = 40; //defense
    tonberry[4] = 15; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    tonStat();

    printf("A TONBERRY charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (tonberry[3] / 10); //tonberry[3] / 10 takes the first number of defense and minuses it from the attack
                    tonberry[0] = tonberry[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (tonberry[3] / 10);
                        tonberry[0] = tonberry[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a might smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }

                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        tonStat();

        if ((tonberry[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between tonberry attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (tonberry[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("TONBERRY attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (tonberry[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("TONBERRY uses butter knife!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        tonStat();

        if ((tonberry[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (tonberry[0] <= 0){
        printf("TONBERRY defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end tonberry fight



    case(2):
    //imp fight
    imp[0] = 25; //health
    imp[1] = 23; //magic
    imp[2] = 28; //attack
    imp[3] = 35; //defense
    imp[4] = 10; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    impStat();

    printf("An IMP charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (imp[3] / 10); //imp[3] / 10 takes the first number of defense and minuses it from the attack
                    imp[0] = imp[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (imp[3] / 10);
                        imp[0] = imp[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }

                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        impStat();

        if ((imp[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (3 seconds)
        randAttack = 1 + rand() % 2; //randomizes between imp attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (imp[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("IMP attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (imp[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("IMP uses gnaw!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        impStat();

        if ((imp[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (imp[0] <= 0){
        printf("IMP defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end imp fight



    case(3):
    //goblin fight
    goblin[0] = 35; //health
    goblin[1] = 23; //magic
    goblin[2] = 28; //attack
    goblin[3] = 35; //defense
    goblin[4] = 10; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    goblinStat();

    printf("A GOBLIN charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (goblin[3] / 10); //goblin[3] / 10 takes the first number of defense and minuses it from the attack
                    goblin[0] = goblin[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (goblin[3] / 10);
                        goblin[0] = goblin[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }
                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        goblinStat();

        if ((goblin[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between goblin attack or magic
        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (goblin[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("GOBLIN attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (goblin[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("GOBLIN uses bomb toss!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        goblinStat();

        if ((goblin[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (goblin[0] <= 0){
        printf("GOBLIN defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end goblin fight

    case(4)://updated sorcerer code
    sorcerer[0] = 35; //health
    sorcerer[1] = 40; //magic
    sorcerer[2] = 22; //attack
    sorcerer[3] = 20; //defense
    sorcerer[4] = 13; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    sorcererStat();

    printf("A SORCERER charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            fleeRand = 0;
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (sorcerer[3] / 10); //sorcerer[3] / 10 takes the first number of defense and minuses it from the attack
                    sorcerer[0] = sorcerer[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (sorcerer[3] / 10);
                        sorcerer[0] = sorcerer[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }

                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        sorcererStat();

        if ((sorcerer[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between sorcerer attack or magic
        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (sorcerer[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("SORCERER attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (sorcerer[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("SORCERER casts fira!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        sorcererStat();

        if ((sorcerer[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (sorcerer[0] <= 0){
        printf("SORCERER defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end sorcerer fight


    case(5):
    //minotaur fight
    minotaur[0] = 45; //health
    minotaur[1] = 35; //magic
    minotaur[2] = 28; //attack
    minotaur[3] = 25; //defense
    minotaur[4] = 11; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    minotaurStat();

    printf("A MINOTAUR charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (minotaur[3] / 10); //minotaur[3] / 10 takes the first number of defense and minuses it from the attack
                    minotaur[0] = minotaur[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (minotaur[3] / 10);
                        minotaur[0] = minotaur[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }
                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        minotaurStat();

        if ((minotaur[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between minotaur attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (minotaur[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("MINOTAUR attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (minotaur[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("MINOTAUR uses charge!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        minotaurStat();

        if ((minotaur[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (minotaur[0] <= 0){
        printf("MINOTAUR defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end minotaur fight



    case(6):
    //harpy fight
    harpy[0] = 35; //health
    harpy[1] = 30; //magic
    harpy[2] = 25; //attack
    harpy[3] = 22; //defense
    harpy[4] = 17; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    harpyStat();

    printf("A HARPY charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (harpy[3] / 10); //harpy[3] / 10 takes the first number of defense and minuses it from the attack
                    harpy[0] = harpy[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (harpy[3] / 10);
                        harpy[0] = harpy[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }
                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        harpyStat();

        if ((harpy[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between harpy attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (harpy[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("HARPY attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (harpy[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("HARPY uses claw!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        harpyStat();

        if ((harpy[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (harpy[0] <= 0){
        printf("HARPY defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end harpy fight



    case(7):
    //ghoul fight
    ghoul[0] = 38; //health
    ghoul[1] = 30; //magic
    ghoul[2] = 21; //attack
    ghoul[3] = 22; //defense
    ghoul[4] = 17; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    ghoulStat();

    printf("A GHOUL charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (ghoul[3] / 10); //ghoul[3] / 10 takes the first number of defense and minuses it from the attack
                    ghoul[0] = ghoul[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (ghoul[3] / 10);
                        ghoul[0] = ghoul[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }
                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        ghoulStat();

        if ((ghoul[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between ghoul attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (ghoul[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("GHOUL attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (ghoul[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("GHOUL uses throw spirit!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        ghoulStat();

        if ((ghoul[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (ghoul[0] <= 0){
        printf("GHOUL defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end ghoul fight



    case(8):
    //lycan fight
    lycan[0] = 40; //health
    lycan[1] = 35; //magic
    lycan[2] = 26; //attack
    lycan[3] = 23; //defense
    lycan[4] = 15; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    lycanStat();

    printf("A LYCAN charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (lycan[3] / 10); //lycan[3] / 10 takes the first number of defense and minuses it from the attack
                    lycan[0] = lycan[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (lycan[3] / 10);
                        lycan[0] = lycan[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }
                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        lycanStat();

        if ((lycan[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between lycan attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (lycan[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("LYCAN attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (lycan[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("LYCAN uses bite!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        lycanStat();

        if ((lycan[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (lycan[0] <= 0){
        printf("LYCAN defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end lycan fight



    case(9):
    //satyr fight
    satyr[0] = 40; //health
    satyr[1] = 27; //magic
    satyr[2] = 36; //attack
    satyr[3] = 32; //defense
    satyr[4] = 16; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    satyrStat();

    printf("A SATYR charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (satyr[3] / 10); //satyr[3] / 10 takes the first number of defense and minuses it from the attack
                    satyr[0] = satyr[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (satyr[3] / 10);
                        satyr[0] = satyr[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }
                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        satyrStat();

        if ((satyr[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between satyr attack or magic

        while (playerTurn == 0){
            switch(randAttack){
                case(1):
                    enemyAttack = (satyr[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("SATYR attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (satyr[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("SATYR uses archery!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        satyrStat();

        if ((satyr[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (satyr[0] <= 0){
        printf("SATYR defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end satyr fight



    case(10):
    //zombie jaguar fight
    zomjag[0] = 40; //health
    zomjag[1] = 25; //magic
    zomjag[2] = 33; //attack
    zomjag[3] = 36; //defense
    zomjag[4] = 22; //evasion

    playerDefend = 0;
    enemyAttack = 0;
    enemyMagic = 0;
    dmgAmount = 0;

    playerStat();
    zomjagStat();

    printf("A ZOMBIE JAGUAR charges toward Sir Albrecht!\n\n");
    while (battle == 1){ //check user input
        while (playerTurn == 1){
            fleeRand = 0;
            playerTurn = 1;
            holdNum = 0;
            memset(&userNum[0], 0, sizeof(userNum));
            printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
            fgets(userNum, sizeof(userNum), stdin);
            valid = CORRECT;
            for (a = 0; a < strlen(userNum); ++a){
                if (!isdigit(userNum[a])){
                    valid = FALSE;
                    break;
                }
            }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (zomjag[3] / 10); //zomjag[3] / 10 takes the first number of defense and minuses it from the attack
                    zomjag[0] = zomjag[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (zomjag[3] / 10);
                        zomjag[0] = zomjag[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }

                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    fleeRand = 1 + rand() % 2;
                    if (fleeRand == 2){
                        printf("\nSir Albrecht fled successfully!\n\n");
                        battle = 0;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nFlee failed..\n\n");
                        playerTurn--;
                        break;
                    }

                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
            }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        zomjagStat();

        if ((zomjag[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between zombie jaguar attack or magic

        while (playerTurn == 0){ //enemy fight
            switch(randAttack){
                case(1):
                    enemyAttack = (zomjag[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("ZOMBIE JAGUAR attacked!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (zomjag[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("ZOMBIE JAGUAR uses undead fang!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        zomjagStat();

        if ((zomjag[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }
    } //endWhile


    if (battle == 0){
        break;
    }
    if (zomjag[0] <= 0){
        printf("ZOMBIE JAGUAR defeated!\n\n");
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        break;
    }

    //end zombie jaguar fight



    default:
            printf("ERROR\n\n");
            break;
    } //end monster selector switch
    }
    battle=0;
    rto7=0;


 if(player[0] <= 0){
    printf("\nSir Albrecht has fallen. His life and his quest end here.\n");
    getchar();
    return(0);
                }

    commandN=0;
    memset(&command[0], 0, sizeof(command));
    printf("\n\nCommand?\n\n       1)North\n  3)West      2)East\n       4)South\n");
    printf("\n\n5)Map    6)Status    7)Potion");
    printf("\n");
    printf("\n");


//command input validity check
fgets(command, sizeof(command), stdin);
valid = TRUE;
for (a = 0; a < strlen(command); ++a)
    {
    if (!isdigit(command[a])){
        valid = FALSE;
        break;}

    sscanf(command, "%d", &commandN); //changes string array to integer for switch case
    }

//switch case for input command
    switch(commandN){
    case(0):
        printf("\nSir Albrecht pauses to scratch his head.\n");
        break;
    case(1): //move north
            i--;
        if(world[i][j]==1){
            printf("\nA wall blocks Sir Albrecht's way.\n");
            worldMap[i][j]=1;
            i++;
            }
        else{
            worldMap[i][j]=4;
            printf("\nSir Albrecht has moved north.\n");
            rto7=rand()%10;
            }
            break;
    case(2):
            j++;
        if(world[i][j]==1){
            printf("\nA wall blocks Sir Albrecht's way.\n");
            worldMap[i][j]=1;
            j--;
            }
        else{
            worldMap[i][j]=4;
            printf("\nSir Albrecht has moved east.\n");
            rto7=rand()%10;
            }
            break;
    case(3):
            j--;
        if(world[i][j]==1){
            printf("\nA wall blocks Sir Albrecht's way.\n");
            worldMap[i][j]=1;
            j++;
            }
        else{
            worldMap[i][j]=4;
            printf("\nSir Albrecht has moved west.\n");
            rto7=rand()%10;
            }
            break;
    case(4):
             i++;
        if(world[i][j]==1){
            printf("\nA wall blocks Sir Albrecht's way.\n");
            worldMap[i][j]=1;
            i--;
            }
        else
            {
            worldMap[i][j]=4;
            printf("\nSir Albrecht has moved south.\n");
            rto7=rand()%10;
            }
            break;
    case(5):
            printf("\nLEGEND: \n0 - unexplored \n4 - explored\n1 - wall\n\n");
              for(x = 0; x < 16; x++) {
                for(y = 0; y < 16; y++) {
                    printf("%d ", worldMap[x][y]);}
                printf("\n");}
            printf("\n");
            break;
    case(6):
            printf("\n");
            playerStat();
            break;
    case(7):
            if(potion>0){
                player[0] = player[0] + (40 + rand() % 15);
                potion--;
                printf("\nSir Albrecht quaffs a healing potion.\n\n");
                playerStat();
                break;
                        }
            else{
                printf("\nSir Albrecht has no healing potions!\n\n");
                break;
                        }
    default:
            printf("\nSir Albrecht pauses to scratch his head.\n");
            break;
    }
    switch(world[i][j]){
    case(0):
            printf("\nSir Albrecht is in an empty hall.\n");
            break;
    case(2):
            printf("\nSir Albrecht is in Felgrin's Armory.\n");
            break;
    case(3):
            if(magicShield > 0){
                    printf("Among the mundane armaments strewn about, Sir Albrecht finds a gleaming shield.\n");
                    printf("It is certain to be magical!\n");
                    printf("Sir Albrecht also finds a healing potion.\n");
                    potion++;
                    player[3] = player[3] + 10;
                    magicShield--;
                    break;}
            else
                    printf("\nSir Albrecht is in Felgrin's Armory.\n");
                    break;
    case(4):
            if(magicRing > 0){
                    printf("\nSeemingly forgotten in a dark corner of Felgrin's keep, Sir Albrecht finds a\n");
                    printf("ring. Sir Albrecht feels stronger when he puts the ring on.\n");
                    player[2] = player[2] + 5;
                    magicRing--;
                    break;}
            else{
                    printf("\nSir Albrecht is in an empty hall.\n");
                    break;}
    case(5):
            printf("\nSir Albrecht is in Felgrin's Alchemy laboratory.\n");
            break;
    case(6):
            if(magicCrystal==1){
                    printf("Here stands an alter upon which sits a crystal, glowing with fell magics.\n");
                    getchar();
                    printf("Sensing the evil of the thing, Sir Albrecht smashes the crystal with his\nholy smite!\n");
                    magicCrystal--;
                    sealedDoor++;
                    printf("\nScattered amidst Felgrin's experiments, Sir Albrecht finds two magical potions\nof healing!\n");
                    potion++;
                    potion++;
                    break;}
            else{
                    printf("\nHere lies the shattered remains of Felgrin's crystal.\n");
                    break;}
    case(7):
            printf("\nSir Albrecht is in Felgrin's treasury.\n");
            break;
    case(8):
            if(sealedDoor==0){
                    printf("\nThe door to Felgrin's sanctuary is sealed by fell magics!\n");
                    printf("\nThe fell energy slams into Sir Albrecht, dealing 50 points of damage!\n");
                    player[0] =  player[0] - 50;
                    i++;
                    break;}
            else{
                    printf("\nWith the fell magics dispelled, the way to Felgrin's sanctuary is open.\n");
                    getchar();
                    break;
                    }
    case(9): //felgrin case
        battle=1;
        playerDefend = 0;
        enemyAttack = 0;
        enemyMagic = 0;
        dmgAmount = 0;

        printf("\nSir Albrecht's brow furrows as he lays eyes upon the Dark Warlock's sanctuary.\n");
        printf("Calmly, he raises his shield and unsheathes his blade, thirsting for blood.\n");
        printf("Albrecht shouts,\n");
        getchar();
        printf("\nFelgrin! Return the Orb to its rightful place and slither from death's grasp\n");
        printf("this day or see this twisted place become your tomb!\n");
        getchar();
        printf("\nThe twisted form of Felgrin laughs, he rises from his seat to ask,\n");
        printf("You offer life or death? If you can grant it, I choose death.\n");
        getchar();
        printf("Sir Albrecht responds,\n");
        printf("Your will... my hand!\n");

        playerStat();
        felgrinStat();

            while (battle == 1){ //check user input
            while (playerTurn == 1){
                fleeRand = 0;
                playerTurn = 1;
                holdNum = 0;
                memset(&userNum[0], 0, sizeof(userNum));
                printf("1)Attack  2)Smite  3)Defend  4)Flee\n\n");
                fgets(userNum, sizeof(userNum), stdin);
                valid = CORRECT;
                for (a = 0; a < strlen(userNum); ++a){
                    if (!isdigit(userNum[a])){
                        valid = FALSE;
                        break;
                    }
                }

            sscanf(userNum, "%d", &holdNum);
            switch(holdNum){ //user battle options
                case(1):
                    dmgAmount = (player[2] / 2) - (felgrin[3] / 10); //felgrin[3] / 10 takes the first number of defense and minuses it from the attack
                    felgrin[0] = felgrin[0] - dmgAmount;
                    printf("\nSir Albrecht attacks!\n\t\t- %d\n\n", dmgAmount);
                    playerTurn--;
                    break;

                case(2):
                    if (magicCount > 0){
                        dmgAmount = (player[1] / 2) - (felgrin[3] / 10);
                        felgrin[0] = felgrin[0] - dmgAmount;
                        printf("\nSir Albrecht channels holy energy into a mighty smite!\n\t\t- %d\n\n", dmgAmount);
                        player[0] = player[0] - 5;
                        magicCount--;
                        playerTurn--;
                        break;
                    }
                    else{
                        printf("\nSir Albrecht's holy energy is depleted.\n\n");
                        break;
                    }

                case(3):
                    playerDefend = 1;
                    printf("\nSir Albrecht braces!\n\n");
                    playerTurn--;
                    break;

                case(4):
                    printf("\nFelgrin's magic prevents Sir Albrecht from fleeing!\n\n");
                        break;


                default:
                    printf("\nI do not understand this command.\n\n");
                    break;
                        }
         }// endWhile (nested)

        if (battle == 0){ //check flee
            break;
        }

        playerStat();
        felgrinStat();

        if ((felgrin[0] <= 0) || (player[0] <= 0)){ //check health
            break;
        }



        Sleep(2000); //sleep 2000 milliseconds (2 seconds)
        randAttack = 1 + rand() % 2; //randomizes between felgrin's attack or magic

        while (playerTurn == 0){ //enemy fight
            switch(randAttack){
                case(1):
                    enemyAttack = (felgrin[2] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyAttack = enemyAttack / 2;
                    }
                    player[0] = player[0] - enemyAttack;
                    randAttack = 0;
                    printf("FELGRIN bombards Sir Albrecht with orbs of shadow!\n\t\t- %d\n\n", enemyAttack);
                    playerTurn++;
                    break;

                case(2):
                    enemyMagic = (felgrin[1] / 2) - (player[3] / 10);
                    if (playerDefend == 1){
                        enemyMagic = enemyMagic / 2;
                    }
                    player[0] = player[0] - enemyMagic;
                    randAttack = 0;
                    printf("FELGRIN casts nova!\n\t\t- %d\n\n", enemyMagic);
                    playerTurn++;
                    break;

            }
        } //endWhile (enemy fight)

        playerStat();
        felgrinStat();

        if (felgrin[0] <= 0 || player[0] <= 0){ //check health
            break;
            }
            } //endWhile felgrin battle loop


    if (battle == 0){
        break;
    }
    if (felgrin[0] <= 0){
        printf("FELGRIN defeated!\n\n");
        win=1;
        break;
    }
    if (player[0] <= 0){
        printf("SIR ALBRECHT defeated...\n\n");
        printf("\nSir Albrecht has fallen. His life and his quest end here.\n");
        getchar();
        return(EXIT_SUCCESS);
    }
    case(10):
        if(magicSword > 0){
            printf("\nBuried in a pile of plundered treasure, Sir Albrecht finds a gleaming sword!\n");
            printf("It is certain to be magical!\n");
            magicSword--;
            player[2] = player[2] + 10;
            break;}
        else{
            printf("\nSir Albrecht is in Felgrin's treasury.\n");
            break;}
    case(11):
        if(potionFindOne > 0){
            printf("\Sir Albrecht finds a small chest, inside is a healing potion!\n");
            potion++;
            potionFindOne--;
            break;}
        else{
            printf("\nHere lies an empty chest.\n");
            break;}
    case(12):
        if(arrowTrap > 0){
            printf("\nAn arrow shoots from a trap placed on the north wall above the chest!\n");
            printf("Sir Albrecht takes 15 points of damage!\n");
            player[0] = player[0] - 15;
            break;}
        else{
            printf("\nSir Albrecht stands in an empty hall. A chest lies to the north.\n");
            break;}
    case(13):
            if(arrowTrapLever > 0){
                printf("\nSir Albrecht finds a lever on the eastern wall, pulling the lever produces an\naudible click.\n");
                arrowTrap--;
                arrowTrapLever--;
                getchar();
                break;}
            else{
                printf("\nHere is a pulled lever.\n");
                break;}
    case(14):
        printf("\nA narrow hallway lies to the north with a chest at the end of it, the floor between\n");
        printf("Sir Albrecht and the chest seems suspicious.\n");
        break;
    case(15):
        if(potionFindTwo > 0){
            printf("\Sir Albrecht finds a small chest, inside is a healing potion!\n");
            potion++;
            potionFindTwo--;
            break;}
        else{
            printf("\nHere lies an empty chest.\n");
            break;}
    case(16):
        if(potionFindThree > 0){
            printf("\Sir Albrecht finds a small chest, inside is a healing potion!\n");
            potion++;
            potionFindThree--;
            break;}
        else{
            printf("\nHere lies an empty chest.\n");
            break;}
    } //endWhile

 }
 printf("\n\nA flurry of lighting bolts streak from Felgrin's staff toward Sir Albrecht,\n");
 printf("he closes in on Felgrin, dashing left and right to avoid being struck.\n");
 getchar();
 printf("Now, closer than ever, Albrecht raises his shield thrusts forward with\nhis blade, straight and true.\n");
 printf("Impaling Felgrin through his chest.\n");
 getchar();
 printf("Felgrin screams.\n");
 printf("GWAGH! What!? This... this cannot be!\n");
 getchar();
 printf("Sir Albrecht grips his blade tightly as he moves to whisper in the Warlock's\near,\n");
 getchar();
 printf("As I said, your will.... my hand.\n");
 printf("Sir Albrecht steps back, ripping the blade from Felgrin's chest. The lifeless\nwarlock ");
 printf("crumbles to his knees as blood, dark as onyx, flows like a waterfall\nonto the floor.\n");
 getchar();
 printf("\nOn a pedestal sits the Orb of Light, which Sir Albrecht reclaims.\n");
 printf("\nHis long and treachorous journey now over, Sir Albrecht returns the orb of light");
 printf("to its rightful place in Vorum, eradicating the miasma once and for all.\n");
 getchar();
 printf("\nThe Clerics of Vorum use the Orb to cure the pestilence, and a ceremony is held\nin");
 printf(" Sir Albrecht's honor, but the joy is short lived when the shadow\nof a mighty dragon passes");
 printf(" overhead.\n\n");
 getchar();
 printf("The King of Vorum proclaims,\n");
 printf("Sir Albrecht!\n");
 getchar();
 printf("Sir Albrecht nods, knowing what he must do.\n\n");
 printf("Your will... my hand.\n\n");
 printf("\nFIN\n");
 getchar();
 printf("\nConceptual Design - Aaron Dee\n");
 printf("\nScenario Progammer - Matthew Young\n");
 printf("\nBattle Programmer - Jarrod Owens\n");
 printf("\nAlgorithm Programmer - Adrian Hall\n");
 printf("\nMarketing - Diana Griffin\n");
 printf("\n\nSpecial thanks to all our friends and family for continued support!\n");
 getchar();
 return(EXIT_SUCCESS);
}

//stat functions
void playerStat(){ //print character stats
    printf(" ------------------------\n");
    printf("|SIR ALBRECHT            |\n");
    if (player[0] > 99){ //health
        printf("|Health Points:  %d     |\n", player[0]);
    }
    if ((player[0] < 100) && (player[0] > 9)){
        printf("|Health Points:  %d      |\n", player[0]);
    }
    if ((player[0] < 10) && (player[0] > 0)){
        printf("|Health Points:  %d       |\n", player[0]);
    }
    if (player[0] <= 0){
        player[0] = 0;
        printf("|Health Points:  %d       |\n", player[0]);
    }
    if (player[1] > 99){ //magic
        printf("|Magic Power:    %d     |\n", player[1]);
    }
    else{
        printf("|Magic Power:    %d      |\n", player[1]);
    }
        if (player[2] > 99){ //attack
        printf("|Attack Power:   %d     |\n", player[2]);
    }
    else{
        printf("|Attack Power:   %d      |\n", player[2]);
    }
        if (player[3] > 99){ //defense
        printf("|Defense Power:  %d     |\n", player[3]);
    }
    else{
        printf("|Defense Power:  %d      |\n", player[3]);
    }
    printf(" ------------------------\n\n");
}

void tonStat(){ //print tonberry stats
    printf(" -----------------------\n");
    printf("|TONBERRY                |\n");
    if (tonberry[0] > 99){ //health
        printf("|Health Points:  %d     |\n", tonberry[0]);
    }
    if ((tonberry[0] < 100) && (tonberry[0] > 9)){
        printf("|Health Points:  %d      |\n", tonberry[0]);
    }
    if ((tonberry[0] < 10) && (tonberry[0] > 0)){
        printf("|Health Points:  %d       |\n", tonberry[0]);
    }
    if (tonberry[0] <= 0){
        tonberry[0] = 0;
        printf("|Health Points:  %d       |\n", tonberry[0]);
    }
    printf(" ------------------------\n\n");
}

void impStat(){ //print imp stats
    printf(" -----------------------\n");
    printf("|IMP                    |\n");
    if (imp[0] > 99){
        printf("|Health Points:  %d     |\n", imp[0]);
    }
    if ((imp[0] < 100) && (imp[0] > 9)){
        printf("|Health Points:  %d     |\n", imp[0]);
    }
    if ((imp[0] < 10) && (imp[0] > 0)){
        printf("|Health Points:  %d      |\n", imp[0]);
    }
    if (imp[0] <= 0){
        imp[0] = 0;
        printf("|Health Points:  %d      |\n", imp[0]);
    }
    printf(" -----------------------\n\n");
}

void goblinStat(){ //print goblin stats
    printf(" -----------------------\n");
    printf("|GOBLIN                 |\n");
    if (goblin[0] > 99){
        printf("|Health Points:  %d     |\n", goblin[0]);
    }
    if ((goblin[0] < 100) && (goblin[0] > 9)){
        printf("|Health Points:  %d     |\n", goblin[0]);
    }
    if ((goblin[0] < 10) && (goblin[0] > 0)){
        printf("|Health Points:  %d      |\n", goblin[0]);
    }
    if (goblin[0] <= 0){
        goblin[0] = 0;
        printf("|Health Points:  %d      |\n", goblin[0]);
    }
    printf(" -----------------------\n\n");
}

void sorcererStat(){ //print goblin stats
    printf(" -----------------------\n");
    printf("|SORCERER               |\n");
    if (sorcerer[0] > 99){
        printf("|Health Points:  %d     |\n", sorcerer[0]);
    }
    if ((sorcerer[0] < 100) && (sorcerer[0] > 9)){
        printf("|Health Points:  %d     |\n", sorcerer[0]);
    }
    if ((sorcerer[0] < 10) && (sorcerer[0] > 0)){
        printf("|Health Points:  %d      |\n", sorcerer[0]);
    }
    if (sorcerer[0] <= 0){
        sorcerer[0] = 0;
        printf("|Health Points:  %d      |\n", sorcerer[0]);
    }
    printf(" -----------------------\n\n");
}

void minotaurStat(){ //print minotaur stats
    printf(" -----------------------\n");
    printf("|MINOTAUR               |\n");
    if (minotaur[0] > 99){
        printf("|Health Points:  %d     |\n", minotaur[0]);
    }
    if ((minotaur[0] < 100) && (minotaur[0] > 9)){
        printf("|Health Points:  %d     |\n", minotaur[0]);
    }
    if ((minotaur[0] < 10) && (minotaur[0] > 0)){
        printf("|Health Points:  %d      |\n", minotaur[0]);
    }
    if (minotaur[0] <= 0){
        minotaur[0] = 0;
        printf("|Health Points:  %d      |\n", minotaur[0]);
    }
    printf(" -----------------------\n\n");
}

void harpyStat(){ //print harpy stats
    printf(" -----------------------\n");
    printf("|HARPY                  |\n");
    if (harpy[0] > 99){
        printf("|Health Points:  %d     |\n", harpy[0]);
    }
    if ((harpy[0] < 100) && (harpy[0] > 9)){
        printf("|Health Points:  %d     |\n", harpy[0]);
    }
    if ((harpy[0] < 10) && (harpy[0] > 0)){
        printf("|Health Points:  %d      |\n", harpy[0]);
    }
    if (harpy[0] <= 0){
        harpy[0] = 0;
        printf("|Health Points:  %d      |\n", harpy[0]);
    }
    printf(" -----------------------\n\n");
}

 void ghoulStat(){ //print ghoul stats
    printf(" -----------------------\n");
    printf("|GHOUL                  |\n");
    if (ghoul[0] > 99){
        printf("|Health Points:  %d     |\n", ghoul[0]);
    }
    if ((ghoul[0] < 100) && (ghoul[0] > 9)){
        printf("|Health Points:  %d     |\n", ghoul[0]);
    }
    if ((ghoul[0] < 10) && (ghoul[0] > 0)){
        printf("|Health Points:  %d      |\n", ghoul[0]);
    }
    if (ghoul[0] <= 0){
        ghoul[0] = 0;
        printf("|Health Points:  %d      |\n", ghoul[0]);
    }
    printf(" -----------------------\n\n");
 }

 void lycanStat(){ //print lycan stats
    printf(" -----------------------\n");
    printf("|LYCAN                  |\n");
    if (lycan[0] > 99){
        printf("|Health Points:  %d     |\n", lycan[0]);
    }
    if ((lycan[0] < 100) && (lycan[0] > 9)){
        printf("|Health Points:  %d     |\n", lycan[0]);
    }
    if ((lycan[0] < 10) && (lycan[0] > 0)){
        printf("|Health Points:  %d      |\n", lycan[0]);
    }
    if (lycan[0] <= 0){
        lycan[0] = 0;
        printf("|Health Points:  %d      |\n", lycan[0]);
    }
    printf(" -----------------------\n\n");
 }

void satyrStat(){ //print satyr stats
    printf(" -----------------------\n");
    printf("|SATYR                  |\n");
    if (satyr[0] > 99){
        printf("|Health Points:  %d     |\n", satyr[0]);
    }
    if ((satyr[0] < 100) && (satyr[0] > 9)){
        printf("|Health Points:  %d     |\n", satyr[0]);
    }
    if ((satyr[0] < 10) && (satyr[0] > 0)){
        printf("|Health Points:  %d      |\n", satyr[0]);
    }
    if (satyr[0] <= 0){
        satyr[0] = 0;
        printf("|Health Points:  %d      |\n", satyr[0]);
    }
    printf(" -----------------------\n\n");
}

void zomjagStat(){ //print zombie jaguar stats
    printf(" -----------------------\n");
    printf("|ZOMBIE JAGUAR          |\n");
    if (zomjag[0] > 99){
        printf("|Health Points:  %d     |\n", zomjag[0]);
    }
    if ((zomjag[0] < 100) && (zomjag[0] > 9)){
        printf("|Health Points:  %d     |\n", zomjag[0]);
    }
    if ((zomjag[0] < 10) && (zomjag[0] > 0)){
        printf("|Health Points:  %d      |\n", zomjag[0]);
    }
    if (zomjag[0] <= 0){
        zomjag[0] = 0;
        printf("|Health Points:  %d        |\n", zomjag[0]);
    }
    printf(" -----------------------\n\n");
}

void felgrinStat(){ //print felgrin stats
    printf(" ------------------------\n");
    printf("|FELGRIN                 |\n");
    if (felgrin[0] > 99){
        printf("|Health Points:??????????|\n");
    }
    if ((felgrin[0] < 100) && (felgrin[0] > 9)){
        printf("|Health Points:??????????|\n");
    }
    if ((felgrin[0] < 10) && (felgrin[0] > 0)){
        printf("|Health Points:??????????|\n");
    }
    if (felgrin[0] <= 0){
        felgrin[0] = 0;
        printf("|Health Points:??????????|\n");
    }
    printf(" ------------------------\n\n");
}