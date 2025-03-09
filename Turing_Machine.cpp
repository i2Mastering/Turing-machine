// Turing Machine (TM) Implementation in C++
// Author: Ike Iloegbu

#include <iostream>
#include <string>

/**
 * A class representing a Turing Machine (TM) that processes binary numbers for addition.
 * The TM reads a binary string with an 'a' separator and computes the sum of the two numbers.
 */
class TM {
private:
    /**
     * Enumeration representing the states of the Turing Machine.
     */
    enum State { dotI, dotJ, dotK, dotL, dotM, dotN, dotO, dotP, retF, retT };

public:
    State currentState = dotI; ///< The current state of the TM.
    int head = 2; ///< The tape head position.

    /**
     * Processes a binary string and performs binary addition.
     *
     * @param c The input binary string.
     * @return The binary sum of the two numbers if valid, otherwise "Invalid".
     */
    std::string ProcessChar(std::string c) {
        while (currentState < retT) {
            switch (currentState) {
                case dotI:
                    if (c.at(head) == '0' || c.at(head) == '1') {
                        currentState = dotI;
                        head++;
                    } else if (c.at(head) == 'a') {
                        currentState = dotJ;
                        head++;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotJ:
                    if (c.at(head) == '0') {
                        currentState = dotJ;
                        head++;
                    } else if (c.at(head) == '1') {
                        currentState = dotK;
                        head++;
                    } else if (c.at(head) == 'e') {
                        currentState = dotO;
                        head--;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotK:
                    if (c.at(head) == '0' || c.at(head) == '1') {
                        currentState = dotK;
                        head++;
                    } else if (c.at(head) == 'e') {
                        currentState = dotL;
                        head--;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotL:
                    if (c.at(head) == '0') {
                        currentState = dotL;
                        c[head] = '1';
                        head--;
                    } else if (c.at(head) == '1') {
                        currentState = dotM;
                        c[head] = '0';
                        head--;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotM:
                    if (c.at(head) == '0' || c.at(head) == '1') {
                        currentState = dotM;
                        head--;
                    } else if (c.at(head) == 'a') {
                        currentState = dotN;
                        head--;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotN:
                    if (c.at(head) == '0') {
                        currentState = dotI;
                        c[head] = '1';
                        head++;
                    } else if (c.at(head) == '1') {
                        currentState = dotN;
                        c[head] = '0';
                        head--;
                    } else if (c.at(head) == 'e') {
                        currentState = dotI;
                        c[head] = '1';
                        head++;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotO:
                    if (c.at(head) == '0') {
                        currentState = dotO;
                        c[head] = '1';
                        head--;
                    } else if (c.at(head) == 'a') {
                        currentState = dotP;
                        c[head] = 'e';
                        head--;
                    } else {
                        currentState = retF;
                    }
                    break;
                case dotP:
                    if (c.at(head) == '0' || c.at(head) == '1') {
                        currentState = dotP;
                        head--;
                    } else if (c.at(head) == 'e') {
                        currentState = retT;
                        head++;
                    } else {
                        currentState = retF;
                    }
                    break;
                default:
                    break;
            }
        }

        std::string results = c.substr(1);
        int rLength = 0;
        for (char x : results) {
            if (x == 'e') {
                break;
            }
            rLength++;
        }

        return (currentState == retT) ? results.substr(0, rLength) : "Invalid";
    }
};

/**
 * Main function that prompts the user for input, processes the binary string,
 * and prints the computed sum of the two numbers.
 *
 * @return 0 upon successful execution.
 */
int main() {
    TM tm;
    std::string Binaryinput;

    std::cout << "Enter a binary number to add. Place an 'a' in the middle of the binary numbers to add: ";
    std::getline(std::cin, Binaryinput);
    std::string BI = "ee" + Binaryinput + "ee";
    std::cout << "The binary sum of your two numbers is: " << tm.ProcessChar(BI) << std::endl;
    return 0;
}
