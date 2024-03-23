#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double map(double x)
{
    return (x - 1) * 0.75 - 1;
}

int main()
{
    ifstream inFile("data.csv");
    ofstream outFile("result.csv");

    if(inFile.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    outFile << "# N Mean" << endl;

    double sum = 0;
    unsigned int i = 1;
    double val = 0;
    double avg = 0;

    while(inFile >> val)
    {
        sum = sum + map(val);
        avg = sum/i;
        outFile << i << " " << scientific << setprecision(17) << avg << endl;
        i++;
    }

    inFile.close();
    outFile.close();

    return 0;
}
