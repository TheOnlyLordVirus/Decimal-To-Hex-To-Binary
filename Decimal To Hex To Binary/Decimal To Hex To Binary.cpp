// Decimal To Hex To Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

// Checks to see if a char array contains only numbers
bool ContainsNumbersOnly(char* text) 
{
    int len = strlen(text);
    bool ret = false;

    for (int i = 0; i < len; i++) 
    {
        if (text[i] <= 0x39 && text[i] >= 0x30) 
        {
            ret = true;
        }

        else 
        {
            ret = false;
            break;
        }
    }
    return ret;
}

int main()
{
    cout << "Hello World! First windows C++ App\n";
    cout << "Enter a Base 10 number to have it converted to a Base 16 number and a Base 2 number.\n" << endl;

    const char base16[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    const int buffer = 0x200;
    char rawInput[buffer];

    while (true)
    {
        // Check for user input.
        cin >> rawInput;

        // If the user input a number.
        if (ContainsNumbersOnly(rawInput))
        {
            // convert the char[] to a int.
            int userNumber = atoi(rawInput);

            // If we can conver to int16.
            if (userNumber < 0 || userNumber > 32767)
            {
                system("CLS");
                cout << "Sorry this only supports up to 16 bits (Decimal 32767)" << endl;
            }

            else
            {
                char hexresult[7] = { "0x0000" };
                char binaryresult[4][4] =
                {
                    { '0', '0', '0', '0' },
                    { '0', '0', '0', '0' },
                    { '0', '0', '0', '0' },
                    { '0', '0', '0', '0' }
                };

                // For the last 4 chars in the result, 
                // Input the remainder of dividing a int by 16 to the correct hex result place,
                // Then set the userNumber to be the divisor to be divided again.
                // (Simple algorithm to convert Base 10 to Base 16)
                for (int i = 5; i > 1; i--)
                {
                    int divisor = userNumber / 16;
                    int remainder = userNumber % 16;
                    userNumber = divisor;

                    // Convert 10 through 15 to letters for hexadecimal. 
                    hexresult[i] = base16[remainder];
                }

                // For the 4 bytes in the hexadecimal result, 
                for (int i = 2, currentbyte = 0; i <= 5; i++, currentbyte++)
                {

                    int hexbyte = hexresult[i] - '0';

                    switch (hexbyte)
                    {
                    case ('A' - '0'):
                        hexbyte = 10;
                        break;

                    case ('B' - '0'):
                        hexbyte = 11;
                        break;

                    case ('C' - '0'):
                        hexbyte = 12;
                        break;

                    case ('D' - '0'):
                        hexbyte = 13;
                        break;

                    case ('E' - '0'):
                        hexbyte = 14;
                        break;

                    case ('F' - '0'):
                        hexbyte = 15;
                        break;
                    }

                    // Convert to binary, byte by byte.
                    int temptotal = 0;
                    if (hexbyte >= 8 && (temptotal + 8) <= hexbyte)
                    {
                        temptotal += 8;
                        binaryresult[currentbyte][0] = '1';
                    }

                    if (hexbyte >= 4 && (temptotal + 4) <= hexbyte)
                    {
                        temptotal += 4;
                        binaryresult[currentbyte][1] = '1';
                    }

                    if (hexbyte >= 2 && (temptotal + 2) <= hexbyte)
                    {
                        temptotal += 2;
                        binaryresult[currentbyte][2] = '1';
                    }

                    if (hexbyte >= 1 && (temptotal + 1) <= hexbyte)
                    {
                        temptotal += 1;
                        binaryresult[currentbyte][3] = '1';
                    }
                }

                // Convert the 4 bytes to one char array.
                string printbinaryresult;

                for (int i = 0, bit = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printbinaryresult += binaryresult[i][j];
                        bit++;
                    }
                }

                // Print results.
                system("CLS");
                cout << "Your number: " << atoi(rawInput) << endl;
                cout << "Base 16: (HexaDecimal) " << hexresult << endl;
                cout << "Base 2: (Binary, int16) " << printbinaryresult << endl;
            }

        }

        // They did not input a number.
        else
        {
            system("CLS");
            cout << "You fucking donkey input a real number!" << endl;
        }
    }

    // End main.
    return 0;
}
