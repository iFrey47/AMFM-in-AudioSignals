from pydub import AudioSegment
import numpy as np

# Define the file path
file_path = r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\WhatsApp Ptt 2024-06-02 at 12.06.28 AM.ogg"

# Load the OGG file
audio = AudioSegment.from_file(file_path, format="ogg")

# Convert to raw audio data
samples = np.array(audio.get_array_of_samples())
if audio.channels == 2:
    samples = samples.reshape((-1, 2))
    samples = samples.mean(axis=1)  # Convert to mono

# Normalize audio
samples = samples / np.max(np.abs(samples))

# Save raw audio data to a binary file
output_path = r"D:\C (Fun Projects)\Audio Signal Modulation Analysis\audio_samples.raw"
samples.astype(np.float32).tofile(output_path)

print("Decoding and saving raw audio data completed.")
