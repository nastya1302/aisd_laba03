#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace sorting {

    struct Stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;
    };

    ostream& operator<<(std::ostream& stream, const Stats& stats) {
        stream << "Comparison count : " << stats.comparison_count << std::endl;
        stream << "Copy count : " << stats.copy_count << std::endl;
        return stream;
    }

    // implementation of sorting by inserts
    Stats sorting_inserts(vector<int>& mas) {
        Stats stats;
        if (mas.size() < 2)
            return stats;
        for (int i = 1; i < mas.size(); i++)
        {
            stats.comparison_count++;
            for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--) {
                swap(mas[j - 1], mas[j]);
                stats.copy_count += 2;
            }
        }
        return stats;
    }

    ostream& operator<<(std::ostream& stream, const vector<int>& mas) {
        for (int i = 0; i < mas.size(); i++)
            stream << mas[i] << " ";
        return stream;
    }

}