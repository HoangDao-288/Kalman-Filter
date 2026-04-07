import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('build/results.csv', sep='\t')

# Create figure with subplots
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 8))

# Plot 1: Ground Truth, Measurement, and Estimate
ax1.plot(data['Time'], data['Ground Truth'], 'g-', label='Ground Truth', linewidth=1)
ax1.plot(data['Time'], data['Measurement'], 'r.', label='Measurement', markersize=4, alpha=0.6)
ax1.plot(data['Time'], data['Estimate'], 'b-', label='Estimate', linewidth=1)
ax1.set_xlabel('Time (s)')
ax1.set_ylabel('Position')
ax1.set_title('Scalar Kalman Filter Results')
ax1.legend()
ax1.grid(True, alpha=0.3)

# Plot 2: Variance over time
ax2.plot(data['Time'], data['Variance'], 'purple', linewidth=2)
ax2.set_xlabel('Time (s)')
ax2.set_ylabel('Variance')
ax2.set_title('Estimation Variance Over Time')
ax2.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('build/kalman_filter_results.png', dpi=150, bbox_inches='tight')
plt.show()

print("Plot saved to build/kalman_filter_results.png")
