// Amplitude Modulation and Demodulation
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// Constants
const int SAMPLE_RATE = 44100;
const double CARRIER_FREQ = 20000.0; // in Hz
const double PI = 3.14159265358979323846;

// To read raw audio data from file
vector<float> readAudioData(const string& filename, size_t& numSamples) {
    ifstream input(filename, ios::binary);

    if (!input) {
        cerr << "Failed to open input file.\n";
        exit(1);
    }

    // Moves the file pointer to the end of the file to determine its size
    input.seekg(0, ios::end);
    //Gets the size of the file in bytes
    size_t fileSize = input.tellg();
    //Moves the file pointer back to the beginning of the file
    input.seekg(0, ios::beg);
    //Calculates the number of samples in the file
    numSamples = fileSize / sizeof(float);

    // Read audio data
    vector<float> samples(numSamples);
    input.read(reinterpret_cast<char*>(samples.data()), fileSize); //reads the data into the sample
    return samples;
}

//function to write audio data to file
void writeAudioData (const string& filename , const vector<float>& samples){
    ofstrean output (filename , ios::binary);

    if (!output){
        cerr << "Failed to open output file\n";
        exit (1);
    }
    output.write (reinterpret_cast<const char*>(samples.data()) , samples.size() * sizeof(float) );

}

int main() {
    size_t numSamples;

    // Read the original audio data
    vector <float> samples = readAudioData("audio_samples.raw" , numSamples);

    //Generate time vector

    vector <double> time(numSamples);
    
    for (size_t i=0; i<numSamples; ++i) {
        time[i] = static_cast<double>(i) / SAMPLE_RATE;
    }
    
}

