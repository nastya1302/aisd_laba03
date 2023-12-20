#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

namespace sorting {

    template<typename T>
    ostream& operator<<(std::ostream& stream, const vector<T>& mas) {
        for (int i = 0; i < mas.size(); i++)
            stream << mas[i] << " ";
        return stream;
    }

    class Animals {
    private:
        string name;
        double weight;

    public:
        Animals() : name(""), weight(0) {}
        Animals(string _name, double _weight) : name(_name), weight(_weight) {}

        string get_name() const {
            return name;
        }

        double get_weigth() const {
            return weight;
        }

        bool operator==(const Animals& other)const {
            return name == other.name && weight == other.weight;
        }

        bool operator>(const Animals& other)const {
            return name == other.name && weight > other.weight || name > other.name;
        }
    };

    ostream& operator<<(std::ostream& stream, const Animals& animals) {
        stream << animals.get_name() << ": " << animals.get_weigth() << "kg" << endl;
        return stream;
    }

    struct Stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;

        Stats& operator+=(const Stats& stats) {
            comparison_count += stats.comparison_count;
            copy_count += stats.copy_count;
            return *this;
        }
    };

    ostream& operator<<(std::ostream& stream, const Stats& stats) {
        stream <<"(" << stats.comparison_count << ", " << stats.copy_count << ")" << endl;
        return stream;
    }

    template<typename T>
    Stats insert_sort(vector<T>& mas) {
        Stats stats; 
        for (int i = 1; i < mas.size(); i++) {
            for (int j = i; j > 0; j--) {
                stats.comparison_count++;
                if (mas[j - 1] > mas[j]) {
                    swap(mas[j - 1], mas[j]);
                    stats.copy_count += 2;
                }
            }
        }
        return stats;
    }

    template<typename T>
    Stats coctail_sort(vector<T>& mas) {
        Stats stats;
        int left = 1, right = mas.size() - 1;
        while (left <= right){
            for (int i = right; i >= left; i--) {
                stats.comparison_count++;
                if (mas[i - 1] > mas[i]) {
                    swap(mas[i - 1], mas[i]);
                    stats.copy_count += 2;
                    cout << mas<<endl;
                }
            }
            left++;
            for (int i = left; i <= right; i++) {
                stats.comparison_count++;
                if (mas[i - 1] > mas[i]) {
                    swap(mas[i - 1], mas[i]);
                    stats.copy_count += 2;
                    cout << mas << endl;
                }
            }
            right--;
        }
        return stats;
    }

    template<typename T>
    void heapify(vector<T>& mas, int size, int i, Stats& stats) {
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
            stats.copy_count += 2;
            heapify(mas, size, largest, stats);
        }
    }

    template<typename T>
    Stats heap_sort(vector<T>& mas) {
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

    //template<typename T>
    vector<int> random_mas(size_t size, int min, int max, int seed) {
        vector<int> mas;
        mt19937 gen(seed);
        uniform_real_distribution<> segment(min, max);
        for (int i = 0; i < size; ++i) {
            int value = segment(gen);
            mas.push_back(value);
        }
        return mas;
    }

    //template<typename T>
    Stats average_stats(int size, Stats(*sorted_func)(vector<int>& arr), int seed) {
        int count = 100;
        Stats stats;
        int min = 0;
        int max = 100000;
        for (int i = 0; i < count; i++) {
            vector<int> mas = random_mas(size, min, max, seed);
            stats += sorted_func(mas);
        }
        stats.comparison_count /= count;
        stats.copy_count /= count;
        return stats;
    }

    template<typename T>
    vector<T> sorted_mas(size_t size) {
        vector<T> mas;
        for (int i = 0; i < size; i++)
            mas.push_back(i);
        return mas;
    }

    template<typename T>
    vector<T> back_sorted_mas(size_t size) {
        vector<T> mas;
        for (int i = size; i > 0; i--)
            mas.push_back(i);
        return mas;
    }

   
}