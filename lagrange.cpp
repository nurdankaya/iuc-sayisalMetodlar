#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

int main() {
    vector<string> line;
    vector<string> numbers;
    vector<float> xs;
    vector<float> fxs;

    string temp;
    ifstream myfile("VERI.TXT");
    int i = 0;
    if (myfile.is_open())
    {
        while (getline(myfile,temp)){

            line.push_back(temp);
            i++;
            string delimiter = " ";
            numbers.push_back(temp.substr(0, temp.find(delimiter)));
            size_t pos = 0;
            pos = temp.find(delimiter);
            temp.erase(0, pos + delimiter.length());
            numbers.push_back(temp.substr(0, temp.find(delimiter)));
        }
   
        for (int j = 0; j < 2 * i; j+=2) {
            xs.push_back(strtof((numbers[j]).c_str(), 0));
            
        }
        for (int j = 1; j < 2 * i; j += 2) {
            fxs.push_back(strtof((numbers[j]).c_str(), 0));
        }

        float x ,p, yp = 0;
        cout << "please enter a value :" << endl;
        cin >> x;
        int l = 0;
        cout << endl << "LAGARNE PARAMETERS" << endl;
        for (int k = 0; k < i; k++)
        {
            p = 1;
            for (int n = 0; n < i; n++)
            {
                if (k != n)
                {
                    p = p * (x - xs[n]) / (xs[k] - xs[n]);
                    
                }
                
            }
            cout << "L " << l << " is " << p << endl;
            l++;
            yp = yp + p * fxs[k];
        }
        cout << endl << "f(" << x << ") is " << yp;
        
        myfile.close();
       
    }else 
        cout << "Unable to open file";

    return 0;
}