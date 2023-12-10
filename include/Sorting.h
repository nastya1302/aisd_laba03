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

    Stats insert_sort(vector<int>& mas) {
        Stats stats;
        if (mas.size() < 2)
            return stats;
        for (int i = 1; i < mas.size(); i++) {
            stats.comparison_count++;
            for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--) {
                swap(mas[j - 1], mas[j]);
                stats.copy_count += 2;
            }
        }
        return stats;
    }

    Stats coctail_sort(vector<int>& mas) {
        Stats stats;
        int left = 1, right = mas.size() - 1;
        while (left <= right){
            for (int i = right; i >= left; i--) {
                stats.comparison_count++;
                if (mas[i - 1] > mas[i]) {
                    swap(mas[i - 1], mas[i]);
                    stats.copy_count += 2;
                }
            }
            left++;
            for (int i = left; i <= right; i++) {
                stats.comparison_count++;
                if (mas[i - 1] > mas[i]) {
                    swap(mas[i - 1], mas[i]);
                    stats.copy_count += 2;
                }
            }
            right--;
        }
        return stats;
    }

    void heapify(vector<int>& mas, int size, int i, Stats& stats) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        stats.comparison_count++;
        if (left < size && mas[left] > mas[largest]) {
            largest = left;
            stats.copy_count++;
        }

        stats.comparison_count++;
        if (right < size && mas[right] > mas[largest]) {
            largest = right;
            stats.copy_count++;
        }

        stats.comparison_count++;
        if (largest != i) {
            swap(mas[i], mas[largest]);
            stats.copy_count++;
            heapify(mas, size, largest, stats);
        }
    }

    Stats heap_sort(vector<int>& mas) {
        Stats stats;
        int size = mas.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(mas, size, i, stats);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(mas[0], mas[i]);
            stats.copy_count += 2;
            heapify(mas, i, 0, stats);
        }
        return stats;
    }

    ostream& operator<<(std::ostream& stream, const vector<int>& mas) {
        for (int i = 0; i < mas.size(); i++)
            stream << mas[i] << " ";
        return stream;
    }

}