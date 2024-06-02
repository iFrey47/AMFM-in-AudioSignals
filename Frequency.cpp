// //Frequency Modulation and Demodulation

// #include <iostream>
// #include <fstream>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <complex>

// using namespace std;

// const int SAMPLE_RATE = 44100;
// const double CARRIER_FREQ = 20000.0;
// const double MODULATION_INDEX = 1.0; //Modulation Index
// const double PI = 3.14159265358979323846;


// //read raw audio data from file 
// vector <float> readAudioData(const string& filename , size_t& numSamples) {
//     ifstream input (filename , ios::binary);

//     if(!input) {
//         cerr<<"Failed to open input file. \n";
//         exit(1);
//     }

//     // determine file size and samples
//     input.seekg (0 , ios::end);
//     size_t fileSize = input.tellg();
//     input.seekg(0 , ios::beg);
//     numSamples = fileSize / sizeof(float);

//     //Read audio data
//     vector <float> samples(numSamples);
//     input.read(reinterpret_cast <char*> (samples.data()), fileSize);
//     return samples;
// }

// //write audio data to file
// void writeAudioData (const string& filename , const vector <float>& samples){
//     ofstream output (filename , ios::binary);

//     if(!output) {
//         cerr << "Failed to open output file. \n";
//         exit(1);
//     }
//     output.write(reinterpret_cast <const char*> (samples.data()), samples.size() * sizeof(float));

// }
// int main() {
//     size_t numSamples;

//     //read the original audio data
//     vector <float> samples = readAudioData("audio_samples.raw" , numSamples);

//     //time vector
//     vector <double> time (numSamples);
//     for (size_t i=0; i<numSamples; ++i) {
//         time[i] = static_cast <double>(i) / SAMPLE_RATE;
//     }  

//     //Frequency Modulation
//     vector<float> modulatedFM (numSamples);
//     double phase = 0.0;
//     for (size_t i=0; i<numSamples; ++i){
//         phase += 2 * PI * (CARRIER_FREQ + MODULATION_INDEX * samples[i] / SAMPLE_RATE);
//         modulatedFM[i] = cos(phase);
//     }
//     writeAudioData ("modulated_fm.raw" , modulatedFM);

//     //Frequency Demodulation
//     vector <float> demodulatedFM (numSamples -1);
//     for (size_t i=0; i<numSamples -1; ++i) {
//         complex <float> analyticSignal (modulatedFM[i] , modulatedFM[i+1]);
//         demodulatedFM[i] = arg(analyticSignal);
//     }

//     //Normalize the demodulated signal
//     float maxVal = *max_element(demodulatedFM.begin() , demodulatedFM.end());
//     for (size_t i=0; i<demodulatedFM.size(); ++i) {
//         demodulatedFM[i] /= maxVal;
//     }
//     writeAudioData ("demodulated_fm.raw" , demodulatedFM);

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <complex>
#include <algorithm> max_element

using namespace std;

const int SAMPLE_RATE = 44100;
const double CARRIER_FREQ = 20000.0;
const double MODULATION_INDEX = 1.0; // Modulation Index
const double PI = 3.14159265358979323846;

// Read raw audio data from file
vector<float> readAudioData(const string& filename, size_t& numSamples) {
    ifstream input(filename, ios::binary);

    if (!input) {
        cerr << "Failed to open input file. \n";
        exit(1);
    }

    // Determine file size and samples
    input.seekg(0, ios::end);
    size_t fileSize = input.tellg();
    input.seekg(0, ios::beg);
    numSamples = fileSize / sizeof(float);

    // Read audio data
    vector<float> samples(numSamples);
    input.read(reinterpret_cast<char*>(samples.data()), fileSize);
    return samples;
}

// Write audio data to file
void writeAudioData(const string& filename, const vector<float>& samples) {
    ofstream output(filename, ios::binary);

    if (!output) {
        cerr << "Failed to open output file. \n";
        exit(1);
    }
    output.write(reinterpret_cast<const char*>(samples.data()), samples.size() * sizeof(float));
}

int main() {
    size_t numSamples;

    // Read the original audio data
    vector<float> samples = readAudioData("audio_samples.raw", numSamples);

    // Time vector
    vector<double> time(numSamples);
    for (size_t i = 0; i < numSamples; ++i) {
        time[i] = static_cast<double>(i) / SAMPLE_RATE;
    }

    // Frequency Modulation
    vector<float> modulatedFM(numSamples);
    double phase = 0.0;
    for (size_t i = 0; i < numSamples; ++i) {
        phase += 2 * PI * (CARRIER_FREQ + MODULATION_INDEX * samples[i]) / SAMPLE_RATE;
        modulatedFM[i] = cos(phase);
    }
    writeAudioData("modulated_fm.raw", modulatedFM);

    // Frequency Demodulation
    vector<float> demodulatedFM(numSamples - 1);
    for (size_t i = 0; i < numSamples - 1; ++i) {
        complex<float> analyticSignal(modulatedFM[i], modulatedFM[i + 1]);
        demodulatedFM[i] = arg(analyticSignal);
    }

    // Normalize the demodulated signal
    float maxVal = *max_element(demodulatedFM.begin(), demodulatedFM.end());
    if (maxVal != 0.0f) { // Avoid division by zero
        for (size_t i = 0; i < demodulatedFM.size(); ++i) {
            demodulatedFM[i] /= maxVal;
        }
    }
    writeAudioData("demodulated_fm.raw", demodulatedFM);

    return 0;
}
