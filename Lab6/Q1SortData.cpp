// Sort Data from files using Heap sort
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct person
{
    int id;
    string name;
    int age;
    int height;
    int weight;
};

vector<person> readCSV(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    vector<person> people;
    string line;

    while (getline(file, line))
    {
        person p;
        stringstream ss(line);
        char comma;

        ss >> p.id >> comma;
        getline(ss, p.name, ',');
        ss >> p.age >> comma >> p.height >> comma >> p.weight;

        people.push_back(p);
    }

    file.close();
    return people;
}

void heapify(vector<person> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].height > arr[largest].height)
        largest = left;

    if (right < n && arr[right].height > arr[largest].height)
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<person> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{

    int input_sizes[] = {10, 1000, 100000, 1000000};

    ofstream timeFile("execution_times.csv");

    for (int i = 0; i < sizeof(input_sizes) / sizeof(input_sizes[0]); i++)
    {
        int input_size = input_sizes[i];
        string filename = "dat" + to_string(input_size) + ".csv";

        clock_t start = clock();
        vector<person> people = readCSV(filename);
        heapSort(people);
        clock_t end = clock();
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        timeFile << input_size << "," << elapsed_time << "\n";

        cout << "Input size: " << input_size << ", Time taken: " << elapsed_time << " seconds" << endl;
    }

    timeFile.close();

    return 0;
}
