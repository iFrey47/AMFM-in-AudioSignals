import numpy as np
import matplotlib.pyplot as plt

# Load saved signals
original = np.fromfile(r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\audio_samples.raw", dtype=np.float32)
modulated_am = np.fromfile(r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\modulated_am.raw", dtype=np.float32)
demodulated_am = np.fromfile(r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\demodulated_am.raw", dtype=np.float32)
modulated_fm = np.fromfile(r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\modulated_fm.raw", dtype=np.float32)
demodulated_fm = np.fromfile(r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\demodulated_fm.raw", dtype=np.float32)

# Plotting signals for comparison
plt.figure(figsize=(15, 10))

plt.subplot(3, 2, 1)
plt.plot(original[:5000])
plt.title("Original Audio Signal")
plt.xlabel("Sample")
plt.ylabel("Amplitude")

plt.subplot(3, 2, 3)
plt.plot(modulated_am[:5000])
plt.title("AM Modulated Signal")
plt.xlabel("Sample")
plt.ylabel("Amplitude")

plt.subplot(3, 2, 5)
plt.plot(demodulated_am[:5000])
plt.title("AM Demodulated Signal")
plt.xlabel("Sample")
plt.ylabel("Amplitude")

plt.subplot(3, 2, 2)
plt.plot(modulated_fm[:5000])
plt.title("FM Modulated Signal")
plt.xlabel("Sample")
plt.ylabel("Amplitude")

plt.subplot(3, 2, 4)
plt.plot(demodulated_fm[:5000])
plt.title("FM Demodulated Signal")
plt.xlabel("Sample")
plt.ylabel("Amplitude")

plt.tight_layout()
plt.savefig(r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\modulation_comparison.png")
plt.show()
