#include <iostream>
void solve()
{
    int n = 10, m = 3;
    int** score = new int*[n];
    for (int i = 0; i < n; i ++)
    {
        score[i] = new int[m];
        for (int j = 0; j < m; j ++)
        {
            score[i][j] = rand() % 50 + 50;
        }
    }
    std::cout << "The data is:" << std::endl;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
            std::cout << score[i][j] << ' ';
        std::cout << std::endl;
    }
    int* sum_score = new int[n]{0};
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
            sum_score[i] += score[i][j];
    }
    int max_score = 150, min_score = 300, max_index = -1, min_index = -1;
    for (int i = 0; i < n; i ++)
    {
        int flag = 0;
        for (int j = 0; j < m; j ++)
        {
            if (score[i][j] < 60)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        if (max_score < sum_score[i]) max_score = sum_score[i], max_index = i;
        if (min_score > sum_score[i]) min_score = sum_score[i], min_index = i;
    }
    if (max_index == -1) std::cout << "Cannot find the best student. All the students have failed." << std::endl;
    else
    {
        std::cout << "The best student is No." << max_index << " with scores: ";
        for (int i = 0; i < m; i ++) std::cout << score[max_index][i] << ' ';
        std::cout << std::endl;
    }
    if (min_index == -1) std::cout << "Cannot find the worst student. All the students have failed." << std::endl;
    else
    {
        std::cout << "The worst student is No." << min_index << " with scores: ";
        for (int i = 0; i < m; i ++) std::cout << score[min_index][i] << ' ';
        std::cout << std::endl; 
    }
    for (int i = 0; i < n; i ++)
        delete []score[i];
    delete []score;
    delete []sum_score;
}
int main()
{
    solve();
    return 0;
}