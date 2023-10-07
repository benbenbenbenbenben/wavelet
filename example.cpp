#include "src/wavelet_all.hpp"
#include <iostream>
#include <chrono> // For timing

int main()
{
    float samplerate_hz(8000.);
    float frequency_min = 100.;
    float frequency_max = 4000.;
    float bands_per_octave = 8;
    wavelet::Filterbank cwt(samplerate_hz,
                            frequency_min,
                            frequency_max,
                            bands_per_octave);
    std::size_t numbands(cwt.size());
    cwt.reset(); // Reset processing

    // Start timing here
    auto start = std::chrono::high_resolution_clock::now();

    int i = 0;
    while (i++ < 8000) {
        double value = 0; // should be a real signal obviously
        cwt.update(value);
        for (unsigned int band=0; band<numbands; band++) {
            // std::cout << cwt.result_complex[band] << " "; // Commented out as per your request
        }
        // std::cout << std::endl; // Commented out as per your request
    }

    // End timing here
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " ms" << std::endl;

    return 0;
}
