/*
   Orion Davis (3003072) ord4@zips.uakron.edu
   The University of Akron
   Computer Science II, Prof. Will
   ASSGN9
*/
#include <iostream>
#include <iomanip>

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);

const unsigned MASK1 = 4278190080;
const unsigned MASK2 = 16711680;
const unsigned MASK3 = 65280;
const unsigned MASK4 = 255;

int main() {
   char characters[4];
   unsigned packed{1633903975}; // a, c, e, g

   std::cout << "The packed character representation is:\n";
   displayBits(packed);

   // demonstrate unpacking of characters
   unpackCharacters(characters, packed);
   std::cout << "\nThe unpacked characters are: ";
   for (size_t i{0}; i < 4; ++i) {
      std::cout << characters[i] << " ";
   }
   std::cout << std::endl;

   std::cout << "\nThe unpacked characters in bits are:" << std::endl;
   for (size_t i{0}; i < 4; ++i) {
      displayBits(characters[i]);
      std::cout << '\n';
   }
   std::cout << '\n';
}

// take apart the characters
void unpackCharacters(char characters[], unsigned pack)
{
	characters[0] = (pack & MASK1) >> 24;
	characters[1] = (pack & MASK2) >> 16;
	characters[2] = (pack & MASK3) >> 8;
	characters[3] = (pack & MASK4);
}

// display the bits of value
void displayBits(unsigned value)
{
    const int SHIFT = 8 * sizeof(unsigned ) - 1;
    const unsigned MASK = 1 << SHIFT;

    std::cout << std::setw(10) << value << " = ";

    for(unsigned i = 1; i <= SHIFT + 1; i++){
        std::cout << (value & MASK ? '1' : '0');
        value <<= 1;
    }
}
