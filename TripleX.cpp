#include <iostream>
#include <ctime>

void GameOver() {
    std::cout << R"(
        w*W*W*W*w
         \"."."/
          //`\\         _______________________
         (/. .\)       |                       |
         (\_o_/)  -----| THANK YOU BRAVE HERO! |
        .-~'='~-.      |_______________________|
       /`~`"Y"`~`\
      / /(_ * _)\ \
     / /  )   (  \ \
     \ \_/\\_//\_/ / 
      \/_) '*' (_\/
        |       |
        |       |
        |       |
        |       |
        |       |
        |       |
        |       |
        |       |
        w*W*W*W*w
    )";
    std::cout << "\n>>> Well done! You have saved a princess... now get your reward!";
}

void PrintIntroductionLogo() 
{
    std::cout << R"(
  _______________________________________
 /                                       \
/   _   _   _                 _   _   _   \
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |______________TripleX______________|  /          
 \_______________________________________/
    )" << std::endl;
    std::cout << "HINT: You need to put 3 numbers which add-up and will multiply as a values above \n\n";
}

void PrintIntroduction(int Difficulty)
{
    std::cout << "\nYou are a brave hero at floor " << Difficulty << " of The Dark Castle, fighting your way into a princess's chamber... \n";
    std::cout << "Monster block your way with black magic's tricks and you need to enter correct codes to brake them all \n\n";
}

bool PlayGame(int Difficulty) 
{
    // Background story printing to the console
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code \n";
    std::cout << "+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct;

    int GuessA, GuessB, GuessC;

    // Store player guess
    std::cout << "\n\nChoose your codes: "; 
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n>>> You have purged the black magic and move forward!\n";
        return true;
    }
    else
    {
        std::cout << "\n>>> Monster: \"You are not prepared!\"\n";
        std::cout << ">>> Monster deceived you, but you need to keep fighting! Try again and purge the witch!\n";
        return false;
    }
}

int main() 
{
    srand(time(NULL)); // Create new random sequence based on time of day

    PrintIntroductionLogo();

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    GameOver();

    return 0;
}