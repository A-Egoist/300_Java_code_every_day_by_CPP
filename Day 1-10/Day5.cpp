#include <iostream>

char score_to_level(int score)
{
    char level = 'E';
    score /= 10;
    switch (score)
    {
    case 10:
    case 9:
        level = 'A';
        break;
    case 8:
        level = 'B';
        break;
    case 7:
        level = 'C';
        break;
    case 6:
        level = 'D';
        break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
        level = 'F';
        break;
    default:
        break;
    }
    return level;
}
void score_to_level_test()
{
    int tempScore = 100;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 91;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 82;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 75;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 66;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 52;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 8;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 120;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
}

int main()
{
    score_to_level_test();
    return 0;
}