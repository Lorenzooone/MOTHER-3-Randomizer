// Mother 3 Randomizer
// Randomizes various values in a Mother 3 GBA rom.

// Copyright 2019 Lorenzooone

#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

uint16_t read16(const char* buffer) {
  const unsigned char* buf = (const unsigned char*)buffer;
  return buf[0] + 
         (buf[1] * 256);
}

void write16(char* buffer, uint16_t value) {
  unsigned char* buf = (unsigned char*)buffer;
  buf[1] = (value >> 8) & 0xFF;
  buf[0] = (value) & 0xFF;
}

uint32_t read32(const char* buffer) {
  const unsigned char* buf = (const unsigned char*)buffer;
  return buf[0] + 
         (buf[1] * 256) + 
         (buf[2] * 65536) + 
         ((uint32_t)buf[3] * 16777216);
}

void write32(char* buffer, uint32_t value) {
  unsigned char* buf = (unsigned char*)buffer;
  buf[3] = (value >> 24);
  buf[2] = (value >> 16) & 0xFF;
  buf[1] = (value >> 8) & 0xFF;
  buf[0] = (value) & 0xFF;
}

// reading an entire binary file
bool ends_with(std::string
  const & a, std::string
  const & b);

// stuff from std that we need, avoiding using the whole namespace (safety)
using std::cin;using std::cout;using std::ifstream;using std::ios;
using std::ofstream;using std::streampos;using std::string;

// main program
int main() {
    std:: minstd_rand simple_rand;
    simple_rand.seed(time(NULL));
    streampos size;
    int i = 0, f = 0, t = 0, g = 0, d = 0, character = 0;
    unsigned int array1[4];
    unsigned int charrand[15];
    unsigned int enemyweakness[2][2];
    unsigned int enebagraph[2][257];
    unsigned int enebaarra[2][257];
    unsigned int enesprsha[2][257];
    unsigned int enebapal[2][257];
    unsigned int enespr[257];
    unsigned int enesprinfo[257];
    unsigned int enesprpal[257];
    unsigned int enefine[257];
    unsigned int enearra[257];
    unsigned int eneove[257];
    unsigned int enedatahigh[257];
    unsigned int enedatafrba[257];
    unsigned int enememo[255];
    unsigned int eneheig[257];
    unsigned int itemgraph[256][288];
    unsigned int itemnumber[256];
    unsigned int charsound[15];
    unsigned int itempal[256];
     // unsigned int enememotur[257];  //Is this needed???
    unsigned char option;
    char * memblock;
    string input, end = ".gba", neo;  // ROM Name
    bool RandomizeCharacterStats = true,
         RandomizeEnemyStats = true,
         RandomizeEnemyGraphics = true,
         RandomizeSeizureRiskyBackgrounds = true,
         RandomizeEnemySprites = true,
         RandomizeGiftBoxes = true,
         RandomizeShopsAndItemPrices = true,
         RandomizeItemStats = true,
         RandomizeItemGraphics = true;
    bool exitMainMenu = false;
    
    i = 0;
    while (not exitMainMenu) {
      cout << "\nType a number to choose one of the following options:\n\n1) "
      "Randomize MOTHER 3!\n2) Choose what you want to randomize!\n3) "
      "Credits!\n0) Exit.\n";
      cin >> option;
      if (option == '0')
        return 1;
      else if (option == '1')
        exitMainMenu = true;
      else if (option == '2') {
        bool exitMenu = false;
        while (not exitMenu) {
          cout << "\nType a number to choose one of the following options:\n\n1) "
          "-Playable Character stats randomization, ";
          if (RandomizeCharacterStats)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n2) -Enemy stats randomization, ";
          if (RandomizeEnemyStats)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n3) --Enemy graphics randomization, ";
          if (RandomizeEnemyStats) {
            if (RandomizeEnemyGraphics)
              cout << "Turn OFF.";
            else
              cout << "Turn ON.";
          } else
            cout << "requires Enemy stats randomization.";
          cout << "\n4) --Enemy seizure risky backgrounds, ";
          if (RandomizeEnemyStats) {
            if (RandomizeSeizureRiskyBackgrounds)
              cout << "Turn ON.";
            else
              cout << "Turn OFF.";
          } else
            cout << "requires Enemy stats randomization.";
          cout << "\n5) -Enemy sprites randomization, ";
          if (RandomizeEnemySprites)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n6) -Gift boxes randomization, ";
          if (RandomizeGiftBoxes)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n7) -Shops and item prices randomization, ";
          if (RandomizeShopsAndItemPrices)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n8) -Item stats randomization, ";
          if (RandomizeItemStats)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n9) -Item graphics randomization, ";
          if (RandomizeItemGraphics)
            cout << "Turn OFF.";
          else
            cout << "Turn ON.";
          cout << "\n\n0) -Go to the previous menu.\n";
          cin >> option;
          if (option == '0')
            exitMenu = true;
          else if ((option == '1') || (option == '2') || (option == '3') ||
            (option == '4') || (option == '5') || (option == '6') ||
            (option == '7') || (option == '8') || (option == '9')) {
            cout << "\n\nThanks for choosing option " << (unsigned char) option <<
              ", here's the updated menu!\n\n\n";
            switch(option) {
              case '1': RandomizeCharacterStats = not RandomizeCharacterStats; break;
              case '2': RandomizeEnemyStats = not RandomizeEnemyStats; break;
              case '3': RandomizeEnemyGraphics = not RandomizeEnemyGraphics; break;
              case '4': RandomizeSeizureRiskyBackgrounds = not RandomizeSeizureRiskyBackgrounds; break;
              case '5': RandomizeEnemySprites = not RandomizeEnemySprites; break;
              case '6': RandomizeGiftBoxes = not RandomizeGiftBoxes; break;
              case '7': RandomizeShopsAndItemPrices = not RandomizeShopsAndItemPrices; break;
              case '8': RandomizeItemStats = not RandomizeItemStats; break;
              case '9': RandomizeItemGraphics = not RandomizeItemGraphics; break;
            }
          } else
            cout << "\nPlease, enter again the number.\n";
        }
      } else if (option == '3')
        cout << "\nApplication from Lorenzooone, many thanks to Jeffman for some "
      "technical help.\nLorenzooone's Twitter: "
      "https://twitter.com/Lorenzooone | Jeffman's Twitter: "
      "https://twitter.com/JeffMan19 !\n";
      else
        cout << "\nPlease, enter again the number.\n";
      g = 0;
    }
    f = 0;
    d = 0;
    option = 0;
    input = "";
    getline(cin, input);
    while (f == 0) {  // Check if the name is valid or not
      input = "";
      cout << "\nType the ROM's name, to end the typing, press Enter.\n";
      getline(cin, input);
      if (ends_with(input, end)) {
        f = 1;
      } else
        cout << "\nName not ending in .gba, retry entering the name.\n";
    }
    neo = input + ".bak";
    ifstream file(input, ios:: in | ios::binary | ios::ate);

    if (file.is_open()) {
      size = file.tellg();
      if (static_cast<int>(size) != 33554432) {
        cout << "\nError! ROM not of 32MB... Perhaps bad dump? Shutting down "
        "everything.";
        return 1;
      }  // Initialize them all
      for (g = 0; g <= 255; g++) {
        for (f = 0; f <= 287; f++) itemgraph[g][f] = 0;
      }
      for (f = 0; f <= 255; f++) {
        itemnumber[f] = 0;
        itempal[f] = 0;
      }
      for (f = 0; f <= 14; f++) charsound[f] = 0;
      for (f = 0; f <= 14; f++) charrand[f] = 0;
      // charrand[f] = 0;
      for (f = 0; f <= 254; f++) enememo[f] = 0;
      for (f = 0; f <= 256; f++) {
        enebagraph[0][f] = 0;
        enebagraph[1][f] = 0;
        enebaarra[0][f] = 0;
        enebaarra[1][f] = 0;
        enebapal[0][f] = 0;
        enebapal[1][f] = 0;
        enesprsha[0][f] = 0;
        enesprsha[1][f] = 0;
        enesprinfo[f] = 0;
        enesprpal[f] = 0;
        enespr[f] = 0;
        enefine[f] = 0;
        enearra[f] = 0;
        eneove[f] = 0;
        enedatahigh[f] = 0;
        enedatafrba[f] = 0;
        eneheig[f] = 0;
         // enememotur[f] = 0;
      }
      memblock = new char[size];
      file.seekg(0, ios::beg);
      file.read(memblock, size);
      file.close();
      ofstream file3(neo, ios::out | ios::binary);

      file3.write(memblock, size);
      file3.close();
      ofstream file2(input, ios::out | ios::binary);
      i = 814434;  // Start of enemy height in battle memory table
      t = 0;
      while (t < 255) {
        enememo[t] = (unsigned char) memblock[i];  // Find out different height
         // values and (maybe) where
         // they're pulled from...
        i = i + 2;
        t = t + 1;
      }
      t = 0;
      i = 837176;  // Start of characters stat table
      g = 0;
      f = 0;
      if (RandomizeCharacterStats) {
        while (i < 842024) {
          while (t <= 10) {
            // Let's take and then randomize HP of character
            d = read32(memblock+i);
            if ((d > 1) && (d < 100000000)) {
              f = d / 2;
              if (d < 2) f = 1;
              g = d - f;
              f = (f * 2) + 1;
              d = simple_rand() % f + g;
            }
            write32(memblock+i, d);

            // Let's take and then randomize PP of characters
            i = i + 4;
            d = read32(memblock+i);
            if ((d > 1) && (d < 100000000)) {
              f = d / 2;
              if (d < 2) f = 1;
              g = d - f;
              f = (f * 2) + 1;
              d = simple_rand() % f + g;
            }
            write32(memblock+i, d);

            i = i + 4;
            g = (unsigned char) memblock[i];
            if ((g > 1) && (g < 255)) {  // Randomize Attack
              d = g / 10;
              if (g < 10) d = 1;
              f = g - d;
              d = (d * 2) + 1;
              g = simple_rand() % d + f;
              if (g > 255) g = 255;
            }
            memblock[i] = g;
            i = i + 1;
            g = (unsigned char) memblock[i];
            if ((g > 1) && (g < 255)) {  // Randomize Defense
              d = g / 10;
              if (g < 10) d = 1;
              f = g - d;
              d = (d * 2) + 1;
              g = simple_rand() % d + f;
              if (g > 255) g = 255;
            }
            memblock[i] = g;
            i = i + 1;
            g = (unsigned char) memblock[i];
            if ((g > 1) && (g < 255)) {  // Randomize IQ
              d = g / 10;
              if (g < 10) d = 1;
              f = g - d;
              d = (d * 2) + 1;
              g = simple_rand() % d + f;
              if (g > 255) g = 255;
            }
            memblock[i] = g;
            i = i + 1;
            g = (unsigned char) memblock[i];
            if ((g > 1) && (g < 255)) {  // Randomize Speed
              d = g / 10;
              if (g < 10) d = 1;
              f = g - d;
              d = (d * 2) + 1;
              g = simple_rand() % d + f;
              if (g > 255) g = 255;
            }
            memblock[i] = g;
            i = i + 1;
            t = t + 1;
            d = 10 * t;  // Randomize Kindness
            g = simple_rand() % d + d;
            memblock[i] = g;
            i = i + 4;
          }
          t = 0;
          i = i + 4;
          i = i + 2;
          while (t <= 31) {
            g = (unsigned char) memblock[i];
            f = (unsigned char) memblock[i - 2];
            if (i <= 837812) {  // Prevent strange things where you re-learn a PSI
              if ((f != 22) && (f != 27)) {
                if ((g >= 1) && (g < 100))  // Randomize PSI Table
                  g = simple_rand() % 65 + 1;
                memblock[i] = g;
              }
            } else if ((f != 11) &&
              (f !=
                7)) {  // Prevent strange things where you re-learn a PSI
              if ((g >= 1) && (g < 100))  // Randomize PSI Table
                g = simple_rand() % 65 + 1;
              memblock[i] = g;
            }
            i = i + 4;
            t = t + 1;
          }
          i = i - 2;
          g = read16(memblock+i);
          if (g > 0) {
            charrand[character] = g;
            character = character + 1;
          }
          i = i + 16;
          t = 0;
          g = 0;
        }
        if (character == 0) {
          cout << "\nAn error has occured while randomizing the characters... "
          "Shutting down!";
          return 1;
        }
        i = 837484;  // Randomize Sound Attacks for characters
        t = 0;
        array1[0] = 0;
        array1[1] = 0;
        array1[2] = 0;
        while (t < 15) {
          d = simple_rand() % character;
          f = charrand[d];
          d = read16(memblock+i);
          if (d > 0) {
            charsound[t] = f;
            write16(memblock+i, f);
          }
          i = i + 324;
          t = t + 1;
          array1[0] = 0;
          array1[1] = 0;
          array1[2] = 0;
        }
      }
      t = 0;
      d = 0;
      g = 0;
      f = 0;
      i = 855480;  // Start of enemy table
      i = i + 4;
      if (RandomizeEnemyStats) {
        while (t < 255) {
          for (g = 0; g <= 1; g++) {
            for (f = 0; f <= 1; f++) enemyweakness[g][f] = 0;
          }
          g = simple_rand() % 10;  // Randomize enemy typing
          memblock[i] = g;
          i = i + 6;
          g = simple_rand() % 242 + 1;  // Randomize Battle Backgrounds and remove
           // empty/seizure risky ones.
          if ((g == 189) || (g == 190) || (g == 191)) g = 192;
          if ((g == 193) || (g == 194)) g = 195;
          if ((g == 201) || (g == 202)) g = 203;
          if (RandomizeSeizureRiskyBackgrounds) {
            if (g == 221) g = 220;
          }
          memblock[i] = g;
          i = i + 2;
          g = simple_rand() % 2 + 148;  // Encounter music
          memblock[i] = g;
          i = i + 2;
          g = simple_rand() % 56 + 1;
          if (g <= 21) {
            if (g == 1)
              memblock[i] =
              static_cast<char> (memblock[i] + 143);  // Randomize music for those who don't have it hard-coded
            else if (g == 2)
              memblock[i] =
              static_cast<char> (memblock[i] + 146);
            else
              memblock[i] = g + 152;
            memblock[i + 1] = 7;
          } else if (g <= 28) {
            if (g == 22)
              memblock[i] = 117;
            else if (g == 23)
              memblock[i] = static_cast<char> (memblock[i] + 145);
            else
              memblock[i] = g + 102;
            memblock[i + 1] = 5;
          } else if (g <= 46) {
            if (g == 29)
              memblock[i] = 123;
            else if (g == 30)
              memblock[i] = static_cast<char> (memblock[i] + 145);
            else if (g <= 40)
              memblock[i] = g + 94;
            else
              memblock[i] = g + 95;
            memblock[i + 1] = 4;
          } else if (g <= 55) {
            if (g == 47)
              memblock[i] = static_cast<char> (memblock[i] + 169);
            else
              memblock[i] = g + 99;
            memblock[i + 1] = 1;
          } else {
            memblock[i] = static_cast<char> (memblock[i] + 169);
            memblock[i + 1] = 0;
          }
          i = i + 2;
          g = simple_rand() % 2 + 1;
          if (g == 1) {  // Randomize victory music
            memblock[i] = 80;
            memblock[i + 1] = 4;
          } else {
            memblock[i] = static_cast<char> (memblock[i] + 151);
            memblock[i + 1] = static_cast<char> (memblock[i] + 7);
          }
          i = i + 2;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 99)) {  // Randomize Level
            d = g / 5;
            if (g < 5) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
          }
          memblock[i] = g;
          i = i + 2;
          // Let's take and then randomize HP
          d = read32(memblock+i);
          if ((d > 1) && (d < 100000000)) {
            f = d / 10;
            if (d < 10) f = 1;
            g = d - f;
            f = (f * 2) + 1;
            d = simple_rand() % f + g;
          }
          write32(memblock+i, d);
          i = i + 4;

           // Let's take and then randomize PP
          d = read32(memblock+i);
          if ((d > 1) && (d < 100000000)) {
            f = d / 10;
            if (d < 10) f = 1;
            g = d - f;
            f = (f * 2) + 1;
            d = simple_rand() % f + g;
          }
          write32(memblock+i, d);
          i = i + 4;

          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Attack
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 1;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Defense
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 1;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize QI
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 1;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Speed
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 5;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Back Attack
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 1;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Back Defense
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 1;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Back QI
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 1;
          g = (unsigned char) memblock[i];
          if ((g > 1) && (g < 255)) {  // Randomize Back Speed
            d = g / 10;
            if (g < 10) d = 1;
            f = g - d;
            d = (d * 2) + 1;
            g = simple_rand() % d + f;
            if (g > 255) g = 255;
          }
          memblock[i] = g;
          i = i + 5;
          f = 0;
          d = 0;
          array1[0] = 0;
          array1[1] = 0;
          array1[2] = 0;
          array1[3] = 0;
          while (f < 20) {  // Randomize Weaknesses
            if ((t != 19) && (t != 16)) {
              g = simple_rand() % 20;
              if (g == 19)
                g = simple_rand() % 10001;
              else if (g <= 5)
                g = 0;
              else
                g = simple_rand() % 201;
              if ((g > (int)enemyweakness[1][1]) && (g >= 100) && (f != 8) &&
                (f != 9) && (f != 1) && (f != 13) && (f != 14) && (f != 15)) {
                if (g > (int)enemyweakness[1][0]) {
                  enemyweakness[1][1] = enemyweakness[1][0];
                  enemyweakness[1][0] = g;
                  enemyweakness[0][1] = enemyweakness[0][0];
                  enemyweakness[0][0] = f;
                } else {
                  enemyweakness[1][1] = g;
                  enemyweakness[0][1] = f;
                }
              }
              if (f == 15) g = 100;
              write16(memblock+i, g);
            }
            i = i + 2;
            f = f + 1;
          }
          array1[0] = 0;
          array1[1] = 0;
          f = 0;
          i = i + 16;
          g = simple_rand() % 59 + 1;
          if (g <= 5) {
            memblock[i] = (3 * g) - 1;  // Randomize Attack Sound
            memblock[i + 1] = 2;
          } else if (g <= 31) {
            if (g == 6)
              memblock[i] = 33;
            else
              memblock[i] = (g * 3) + 162;
            memblock[i + 1] = 1;
          } else {
            if (g <= 47)
              memblock[i] = (3 * g) - 12;
            else if (g <= 54)
              memblock[i] = (3 * g) - 9;
            else
              memblock[i] = (3 * g) - 6;
            memblock[i + 1] = 3;
          }
          i = i + 8;
          enedatahigh[t] =
            (unsigned char) memblock[i];  // Get enemy sprite in-battle height
          i = i + 4;
          eneheig[t] = read16(memblock+i); // Get memo height modifiers
          i = i + 2;
          enedatafrba[t] = read16(memblock+i);  // Get in-battle height modifiers
          i = i + 2;
           // enememotur[t] = (unsigned char)memblock[i];  //Get enemy turnability
           // in Battle Memory
          i = i + 4;
          g = simple_rand() % 4;
          if (t != 101) {  // Let's have Stinky Ghosts maintain their drop
            if (g == 0) {  // No drops
              for (f = 0; f < 12; f++) memblock[i + f] = 0;
            } else if (g == 1) {  // One drop
              f = simple_rand() % 192 + 1;
              if ((f > 174) && (f <= 180))
                f = f + 1;
              else if (f == 181)
                f = 183;
              else if ((f > 181) && (f <= 186))  // Randomize Item Drops
                f = f + 3;
              else if (f == 187)
                f = 191;
              else if ((f > 187) && (f <= 190))
                f = f + 6;
              else
                f = f + 7;
              memblock[i] = f;
              f = simple_rand() % 100 + 1;
              memblock[i + 1] = f;
              for (f = 2; f < 12; f++) memblock[i + f] = 0;
            } else if (g == 2) {  // Two Drops
              f = simple_rand() % 192 + 1;
              if ((f > 174) && (f <= 180))
                f = f + 1;
              else if (f == 181)
                f = 183;
              else if ((f > 181) && (f <= 186))
                f = f + 3;
              else if (f == 187)
                f = 191;
              else if ((f > 187) && (f <= 190))
                f = f + 6;
              else
                f = f + 7;
              memblock[i] = f;
              f = simple_rand() % 80 + 1;
              memblock[i + 1] = f;
              memblock[i + 2] = 0;
              memblock[i + 3] = 0;
              f = simple_rand() % 192 + 1;
              if ((f > 174) && (f <= 180))
                f = f + 1;
              else if (f == 181)
                f = 183;
              else if ((f > 181) && (f <= 186))
                f = f + 3;
              else if (f == 187)
                f = 191;
              else if ((f > 187) && (f <= 190))
                f = f + 6;
              else
                f = f + 7;
              memblock[i + 4] = f;
              f = simple_rand() % 80 + 1;
              memblock[i + 5] = f;
              for (f = 6; f < 12; f++) memblock[i + f] = 0;
            } else {  // Three drops
              f = simple_rand() % 192 + 1;
              if ((f > 174) && (f <= 180))
                f = f + 1;
              else if (f == 181)
                f = 183;
              else if ((f > 181) && (f <= 186))
                f = f + 3;
              else if (f == 187)
                f = 191;
              else if ((f > 187) && (f <= 190))
                f = f + 6;
              else
                f = f + 7;
              memblock[i] = f;
              f = simple_rand() % 70 + 1;
              memblock[i + 1] = f;
              memblock[i + 2] = 0;
              memblock[i + 3] = 0;
              f = simple_rand() % 192 + 1;
              if ((f > 174) && (f <= 180))
                f = f + 1;
              else if (f == 181)
                f = 183;
              else if ((f > 181) && (f <= 186))
                f = f + 3;
              else if (f == 187)
                f = 191;
              else if ((f > 187) && (f <= 190))
                f = f + 6;
              else
                f = f + 7;
              memblock[i + 4] = f;
              f = simple_rand() % 70 + 1;
              memblock[i + 5] = f;
              memblock[i + 6] = 0;
              memblock[i + 7] = 0;
              f = simple_rand() % 192 + 1;
              if ((f > 174) && (f <= 180))
                f = f + 1;
              else if (f == 181)
                f = 183;
              else if ((f > 181) && (f <= 186))
                f = f + 3;
              else if (f == 187)
                f = 191;
              else if ((f > 187) && (f <= 190))
                f = f + 6;
              else
                f = f + 7;
              memblock[i + 8] = f;
              f = simple_rand() % 70 + 1;
              memblock[i + 9] = f;
              for (f = 10; f < 12; f++) memblock[i + f] = 0;
            }
          }
          i = i + 12;

          // Let's take and then randomize EXP
          d = read32(memblock+i);
          if ((d > 1) && (d < 10000000)) {
            f = d / 10;
            if (d < 10) f = 1;
            g = d - f;
            f = (f * 2) + 1;
            d = simple_rand() % f + g;
          }
          write32(memblock+i, d);
          i = i + 4;

          // Let's take and then randomize Money
          d = read32(memblock+i);
          if ((d > 1) && (d < 10000000)) {
            f = d / 10;
            if (d < 10) f = 1;
            g = d - f;
            f = (f * 2) + 1;
            d = simple_rand() % f + g;
          }
          write32(memblock+i, d);
          i = i + 4;

          if (t != 19) {
            if (enemyweakness[1][0] == 0) {
              array1[0] = 230;  // Let's make the game print correct weaknesses
              array1[1] = 1;
              array1[2] = 230;
              array1[3] = 1;
            } else if (enemyweakness[1][1] == 0) {
              if (enemyweakness[0][0] <= 7)
                array1[0] = 12 + enemyweakness[0][0];
              else if (enemyweakness[0][0] == 10)
                array1[0] = 22;
              else if (enemyweakness[0][0] == 11)  // DCMC
                array1[0] = 50;
              else if (enemyweakness[0][0] == 12)  // Wall Staples
                array1[0] = 52;
              else
                array1[0] = enemyweakness[0][0] - 13;
              array1[1] = 2;
              array1[2] = 230;
              array1[3] = 1;
            } else {
              if (enemyweakness[0][0] <= 7)
                array1[0] = 12 + enemyweakness[0][0];
              else if (enemyweakness[0][0] == 10)
                array1[0] = 22;
              else if (enemyweakness[0][0] == 11)  // DCMC
                array1[0] = 50;
              else if (enemyweakness[0][0] == 12)  // Wall Staples
                array1[0] = 52;
              else
                array1[0] = enemyweakness[0][0] - 13;
              array1[1] = 2;
              if (enemyweakness[0][1] <= 7)
                array1[2] = 12 + enemyweakness[0][1];
              else if (enemyweakness[0][1] == 10)
                array1[0] = 22;
              else if (enemyweakness[0][1] == 11)  // DCMC
                array1[2] = 50;
              else if (enemyweakness[0][1] == 12)  // Wall Staples
                array1[2] = 52;
              else
                array1[2] = enemyweakness[0][1] - 13;
              array1[3] = 2;
            }
            for (f = 0; f <= 3; f++) memblock[i + f] = array1[f];
          }
          i = i + 8;
          t = t + 1;
        }
      }
       // Let's randomize items price
      t = 0;
      i = 938258;
      if (RandomizeShopsAndItemPrices) {
        while (t < 256) {
          for (f = 0; f < 2; f++) array1[f] = (unsigned char) memblock[i + f];
          d = read16(memblock+i);  // Let's take and then randomize Price
          for (f = 0; f <= 3; f++) array1[f] = 0;
          if (d > 1) {
            f = d / 5;
            if (d < 5) f = 1;
            g = d - f;
            f = (f * 2) + 1;
            d = simple_rand() % f + g;
          }
          write16(memblock+i, d);
          t = t + 1;
          i = i + 108;
        }
        t = 0;
        i = 965896;
        while (t < 36) {
          d = simple_rand() % 30 + 1;
          g = d;
          while (d > 0) {
            f = simple_rand() % 192 + 1;
            if ((f > 174) && (f <= 180))
              f = f + 1;  // Randomize items sold in shops
            else if (f == 181)
              f = 183;
            else if ((f > 181) && (f <= 186))
              f = f + 3;
            else if (f == 187)
              f = 191;
            else if ((f > 187) && (f <= 190))
              f = f + 6;
            else if (f > 190)
              f = f + 7;
            memblock[i] = f;
            i = i + 2;
            d = d - 1;
            if (d == 0) {
              g = 30 - g;
              memblock[i] = 0;
              while (g > 0) {
                i = i + 2;
                memblock[i] = 0;
                g = g - 1;
              }
            }
          }
          t = t + 1;
        }
      }
      i = 18185449;
      memblock[i] = static_cast<char> (80);
      memblock[i + 1] = static_cast<char> (20);
      memblock[i + 3] = static_cast<char> (224);  // Lets prevent something...
      memblock[i + 9] = static_cast<char> (27);
      i = 18242596;  // Beginning of Gift Box Table
      g = 0;
      if (RandomizeGiftBoxes) {
        while (i <= 18253824) {
          g = (unsigned char) memblock[i];
          if ((g != 0) && (g != 175) && (g != 182) && (g != 184) && (g != 190) &&
            (g != 192) && (g != 193) && (g != 197) && (g < 200)) {
            g = simple_rand() % 192 + 1;
            if ((g > 174) && (g <= 180))
              g = g + 1;  // Randomize items in gift boxes
            else if (g == 181)
              g = 183;
            else if ((g > 181) && (g <= 186))
              g = g + 3;
            else if (g == 187)
              g = 191;
            else if ((g > 187) && (g <= 190))
              g = g + 6;
            else if (g >= 191)
              g = g + 7;
            memblock[i] = g;
          }
          i = i + 8;
          g = (unsigned char) memblock[i];
          if ((g == 1) || (g == 33) || (g == 129)) {
            f = simple_rand() % 2;
            if (f == 0)  // Randomize colour of gift boxes
              g = g + 2;
            memblock[i] = g;
          }
          i = i + 8;
        }
      }
      i = 21202924;  // Start of enemy sprites...
      t = 1;
      g = 0;
      if (RandomizeEnemySprites) {
        while (t <= 185) {
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            // Let's take and then randomize HP
            enespr[t] = read32(memblock+i);
            eneove[g] = t;
            g = g + 1;
          }
          i = i + 4;
          t = t + 1;
        }
        i = 21197434;  // Start of something???
        t = 1;
        while (t <= 185) {
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            enesprsha[0][t] = read32(memblock+i);
            enesprsha[1][t] = read16(memblock+i+4);
          }
          i = i + 6;
          t = t + 1;
        }
        i = 27530580;  // Start of sprite palettes
        t = 1;
        while (t <= 185) {
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            enesprpal[t] = read32(memblock+i);
          }
          i = i + 4;
          t = t + 1;
        }
        i = 27543212;  // Start of sprite info... What the hell is this for? I'll
         // just pretend I do know...
        t = 1;
        while (t <= 185) {
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            enesprinfo[t] = read32(memblock+i);
          }
          i = i + 4;
          t = t + 1;
        }
        i = 21202924;  // Start of enemy sprites...
        t = 1;
        while (t <= 185) {
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            for (f = 0; f <= 3; f++) array1[f] = 0;
            f = simple_rand() % g;
            d = eneove[f];
            enearra[t] = d;  // Making sure Sprites get the correct Arrangements
             // and Palettes
            write32(memblock+i, enespr[d]);
          }
          i = i + 4;
          t = t + 1;
        }
        i = 21197434;  // Start of something???
        t = 1;
        while (t <= 185) {  // Putting back sprite palette pointers
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            for (f = 0; f <= 3; f++) array1[f] = 0;
            d = enearra[t];
            write32(memblock+i, enesprsha[0][d]);
            write16(memblock+i+4, enesprsha[1][d]);
          }
          for (f = 0; f <= 3; f++) array1[f] = 0;
          t = t + 1;
          i = i + 6;
        }
        i = 27530580;  // Start of sprite palettes
        t = 1;
        while (t <= 185) {  // Putting back sprite palette pointers
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            for (f = 0; f <= 3; f++) array1[f] = 0;
            d = enearra[t];
            write32(memblock+i, enesprpal[d]);
          }
          t = t + 1;
          i = i + 4;
        }
        i = 27543212;
        t = 1;
        while (t <= 185) {  // Putting back info pointers
          if ((t != 1) && (t != 2) && (t != 3) && (t != 5) && (t != 6) &&
            (t != 7) && (t != 8) && (t != 9) && (t != 11) && (t != 12) &&
            (t != 13) && (t != 14) && (t != 15) && (t != 16) && (t != 17) &&
            (t != 19) && (t != 20) && (t != 21) && (t != 22) && (t != 23) &&
            (t != 24) && (t != 25) && (t != 26) && (t != 27) && (t != 28) &&
            (t != 29) && (t != 30) && (t != 33) && (t != 40) && (t != 46) &&
            (t != 56) && (t != 61) && (t != 66) && (t != 84) && (t != 91) &&
            (t != 92) && (t != 101) && (t != 111) && (t != 133) && (t != 141) &&
            (t != 142) && (t != 145) && (t != 160) && (t != 162) &&
            (t != 163) && (t != 169) && (t != 180) && (t != 181)) {
            for (f = 0; f <= 3; f++) array1[f] = 0;
            d = enearra[t];
            write32(memblock+i, enesprinfo[d]);
          }
          t = t + 1;
          i = i + 4;
        }
      }
      i = 29952424;  // Start of enemy battle graphics pointers
      g = 0;
      if (RandomizeEnemyStats) {
        if (RandomizeEnemyGraphics) {
          for (t = 0; t < 257; t++) {
            d = 0;
            // Let's take and then randomize HP
            enebagraph[0][t] = read32(memblock+i);
            enebagraph[1][t] = read32(memblock+i+4);
            i = i + 8;
            if (enebagraph[1][t] > 48) {
              if (g > 0) {
                for (f = 0; f < g; f++) {
                  if (enebagraph[1][t] == enebagraph[1][f]) {
                    if (d >= 3) f = g;
                    d = d + 1;  // Prevent too many copies, like PORKY bots
                  }
                }
              }
              if (d < 4) {
                enefine[g] = t;
                g = g + 1;
              }
            }
          }
          if (g == 0) {
            cout << "\nAn error has occured while randomizing the graphics... "
            "Shutting down!";
            return 1;
          }
          i = 29957768;  // Start of enemy arrangements pointers
          for (t = 0; t < 257; t++) {
            enebaarra[0][t] = read32(memblock+i);
            enebaarra[1][t] = read32(memblock+i+4);
            i = i + 8;
          }
          i = 29955376;  // Start of enemy graphics palettes pointers
          for (t = 0; t < 257; t++) {
            enebapal[0][t] = read32(memblock+i);
            enebapal[1][t] = read32(memblock+i+4);
            i = i + 8;
          }
          i = 29952424;
          // Picked pointer values... Now let's randomize them
          d = 0;
          for (t = 0; t < 257; t++) {
            f = simple_rand() % g;
            d = enefine[f];
            enearra[t] = d;  // Making sure Battle Sprites get the correct
             // Arrangements and Palettes
            write32(memblock+i, enebagraph[0][enefine[f]]);
            write32(memblock+i+4, enebagraph[1][enefine[f]]);
            i = i + 8;
          }
          i = 29957768;
          // Picked arrangements pointer values... Now let's randomize them
          d = 0;
          for (t = 0; t < 257; t++) {
            write32(memblock+i, enebaarra[0][enearra[t]]);
            write32(memblock+i+4, enebaarra[1][enearra[t]]);
            i = i + 8;
          }
          i = 29955376;  // Start of enemy graphics palettes pointers
          for (t = 0; t < 257; t++) {
            write32(memblock+i, enebapal[0][enearra[t]]);
            write32(memblock+i+4, enebapal[1][enearra[t]]);
            i = i + 8;
          }
          i = 855588;
          t = 0;
          d = 0;
          while (t < 255) {
            d = enearra[t + 1];
            if ((d - 1) < 0) d = 255;
            f = enedatahigh[d - 1];
            memblock[i] = f;  // Putting back height value in-battle
            i = i + 144;
            t = t + 1;
          }
          i = 855594;
          t = 0;
          d = 0;
          while (t < 255) {
            array1[0] = 0;
            array1[1] = 0;
            d = enearra[t + 1];
            if ((d - 1) < 0) d = 255;
            write16(memblock+i, enedatafrba[d-1]); // Putting back height values in-battle modifiers
            i = i + 144;
            t = t + 1;
          }
          i = 855592;
          t = 0;
          while (t < 255) {
            array1[0] = 0;
            array1[1] = 0;
            d = enearra[t + 1];
            if ((d - 1) < 0) d = 255;
            write16(memblock+i, eneheig[d-1]); // Putting back height values in
             // Battle Memory Modifiers
            i = i + 144;
            t = t + 1;
        }
        /*  i = 855596;  //Not needed
 t = 0;
 while (t < 255) {
         d = enearra[t + 1];
         if ((d - 1) < 0)
                 d = 255;
         f = enememotur[d - 1];
         memblock[i] = f;  //Putting back height value in-battle
         i = i + 144;
         t = t + 1;
 } */
        i = 814434;   // Putting back height values for memo menu
        t = 0;
        while (t <= 254) {
          d = enearra[t];
          if (d >= 255) d = 254;
          f = enememo[d];
          memblock[i] = f;
          t = t + 1;
          i = i + 2;
        }
      }
    }
    i = 26426416;   // Get items garphics
    t = 0;
    if (RandomizeItemGraphics) {
      character = 0;
      while (t <= 241) {
        for (g = 0; g <= 287; g++)
          itemgraph[t][g] = (unsigned char)memblock[i + g];
        t = t + 1;
        i = i + 288;
      }
      t = 0;
      i = 21192521;
      while (t <= 255) {
        itempal[t] = (unsigned char)memblock[i];
        t = t + 1;
        i = i + 12;
      }
      g = 0;
      t = 0;
      i = 26426416;   // Randomize items garphics
      while (t <= 255) {
        if (t != 144) {
          while (g == 0) {
            d = simple_rand() % 242;
            if (d != 144) g = 1;
          }
          for (g = 0; g <= 287; g++) memblock[i + g] = itemgraph[d][g];
          itemnumber[t] = d;
        }
        t = t + 1;
        i = i + 288;
        g = 0;
      }
      t = 0;
      i = 21192521;
      while (t <= 255) {
        d = itemnumber[t];
        if (t != 144) {
          f = itempal[d];
          memblock[i] = f;
        }
        t = t + 1;
        i = i + 12;
      }
    }
    i = 938360;   // Randomize item damage, attack and recovery
    t = 0;
    if (RandomizeItemStats) {
      while (t < 255) {
        if (t != 156) {
          d = (unsigned char)memblock[i];
          f = (unsigned char)memblock[i + 4];
          if ((d == 0) && (f == 1)) {   // Randomize stats of Weapons
            g = simple_rand() % 6;
            if (g == 5) {
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 65 + 1;
                if (g >= 51) g = g + 200;
                memblock[i + 12] = g;
                if (g >= 51) {
                  memblock[i + 13] = static_cast<char>(255);
                  memblock[i + 14] = static_cast<char>(255);
                  memblock[i + 15] = static_cast<char>(255);
                } else {
                  memblock[i + 13] = 0;
                  memblock[i + 14] = 0;
                  memblock[i + 15] = 0;
                }
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 65 + 1;
                if (g >= 51) g = g + 200;
                memblock[i + 16] = g;
                if (g >= 51)
                  memblock[i + 17] = static_cast<char>(255);
                else
                  memblock[i + 17] = 0;
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 15 + 1;
                if (g >= 11) g = g + 240;
                memblock[i + 21] = g;
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 15 + 1;
                if (g >= 11) g = g + 240;
                memblock[i + 22] = g;
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 15 + 1;
                if (g >= 11) g = g + 240;
                memblock[i + 23] = g;
              }
            } else {
              memblock[i + 12] = 0;
              memblock[i + 16] = 0;
              memblock[i + 21] = 0;
              memblock[i + 22] = 0;
              memblock[i + 23] = 0;
            }
            g = simple_rand() % 6;
            if (g == 5)
              g = simple_rand() % 50 + 51;
            else if (g <= 2)
              g = simple_rand() % 30 + 1;
            else
              g = simple_rand() % 30 + 26;
            memblock[i + 20] = g;
            g = simple_rand() % 37;
            if (g <= 10) {   // Randomize Ailment Resistances
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = (g * 2) + 28;
              memblock[i + g] = f;
              memblock[i + (g + 1)] = static_cast<char>(255);
            } else if (g >= 35) {
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = simple_rand() % 11;
              g = (g * 2) + 28;
              memblock[i + g] = f;
              memblock[i + (g + 1)] = static_cast<char>(255);
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = simple_rand() % 11;
              g = (g * 2) + 28;
              memblock[i + g] = f;
              memblock[i + (g + 1)] = static_cast<char>(255);
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = simple_rand() % 11;
              g = (g * 2) + 28;
              memblock[i + g] = f;
              memblock[i + (g + 1)] = static_cast<char>(255);
            }
            g = simple_rand() % 25;   // Randomize PSI Resistances
            if (g <= 4) {
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = g + 50;
              memblock[i + g] = f;
            } else if (g >= 23) {
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = simple_rand() % 5;
              g = g + 50;
              memblock[i + g] = f;
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = simple_rand() % 5;
              g = g + 50;
              memblock[i + g] = f;
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = simple_rand() % 5;
              g = g + 50;
              memblock[i + g] = f;
            }
          } else if ((d <= 3) && (f == 1)) {
            g = simple_rand() % 6;   // Randomize stats of Headgear & Co.
            if (g == 5) {
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 35 + 1;
                if (g >= 31) g = g + 220;
                memblock[i + 12] = g;
                if (g >= 51) {
                  memblock[i + 13] = static_cast<char>(255);
                  memblock[i + 14] = static_cast<char>(255);
                  memblock[i + 15] = static_cast<char>(255);
                } else {
                  memblock[i + 13] = 0;
                  memblock[i + 14] = 0;
                  memblock[i + 15] = 0;
                }
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 35 + 1;
                if (g >= 31) g = g + 220;
                memblock[i + 16] = g;
                if (g >= 51)
                  memblock[i + 17] = static_cast<char>(255);
                else
                  memblock[i + 17] = 0;
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 15 + 1;
                if (g >= 11) g = g + 240;
                memblock[i + 20] = g;
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 15 + 1;
                if (g >= 11) g = g + 240;
                memblock[i + 22] = g;
              }
              f = simple_rand() % 5;
              if (f == 4) {
                g = simple_rand() % 15 + 1;
                if (g >= 11) g = g + 240;
                memblock[i + 23] = g;
              }
            } else {
              memblock[i + 12] = 0;
              memblock[i + 16] = 0;
              memblock[i + 22] = 0;
              memblock[i + 23] = 0;
            }
            g = simple_rand() % 6;
            if (g == 5)
              g = simple_rand() % 35 + 41;
            else if (g <= 2)
              g = simple_rand() % 20 + 1;
            else
              g = simple_rand() % 30 + 16;
            memblock[i + 21] = g;
            g = simple_rand() % 37;
            if (g <= 10) {   // Randomize Ailment Resistances
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = (g * 2) + 28;
              memblock[i + g] = f;
            } else if (g >= 35) {
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = simple_rand() % 11;
              g = (g * 2) + 28;
              memblock[i + g] = f;
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = simple_rand() % 11;
              g = (g * 2) + 28;
              memblock[i + g] = f;
              f = simple_rand() % 80 + 1;
              f = f + 175;
              g = simple_rand() % 11;
              g = (g * 2) + 28;
              memblock[i + g] = f;
            }
            g = simple_rand() % 25;   // Randomize PSI Resistances
            if (g <= 4) {
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = g + 50;
              memblock[i + g] = f;
            } else if (g >= 23) {
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = simple_rand() % 5;
              g = g + 50;
              memblock[i + g] = f;
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = simple_rand() % 5;
              g = g + 50;
              memblock[i + g] = f;
              f = simple_rand() % 20 + 1;
              f = f + 235;
              g = simple_rand() % 5;
              g = g + 50;
              memblock[i + g] = f;
            }
          } else if (((d == 4) || (d == 6)) &&
                     (f == 1)) {   // Randomize Throwable items/Healing items
            if (d == 6) {
              g = simple_rand() % 5;   // Randomize Throwable items typing
              memblock[i + 64] = g;
            }
            g = simple_rand() % 300 + 1;
            d = g;
            write16(memblock+i+74, g);
            g += simple_rand() % 50 + 1;
            write16(memblock+i+76, g);
          }
        }
        i = i + 108;
        t = t + 1;
      }
    }
    file2.write(memblock, size);
    file2.close();
    cout << "\nSuccess!\n";
    delete[] memblock;
  } else {
    cout << "\nUnable to open file!";
    return 1;
  }
  return 0;
}

bool ends_with(string const &a, string const &b) {
  auto len = b.length();
  auto pos = a.length() - len;
  if (pos < 0) return false;
  auto pos_a = &a[pos];
  auto pos_b = &b[0];
  while (*pos_a)
    if (*pos_a++ != *pos_b++) return false;
  return true;
}
