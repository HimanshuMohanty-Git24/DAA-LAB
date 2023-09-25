import matplotlib.pyplot as plt
import csv

# Read execution times from the CSV file
input_sizes = []
execution_times = []

with open("execution_times.csv", "r") as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        input_sizes.append(row[0])
        execution_times.append(float(row[1]))

# Create a plot
plt.figure(figsize=(10, 6))
plt.plot(input_sizes, execution_times, marker='o', linestyle='-')
plt.title("Heap Sort Execution Time vs. Input Size")
plt.xlabel("Input Size (File Names)")
plt.ylabel("Execution Time (seconds)")
plt.xticks(rotation=45)
plt.grid(True)

# Show the plot or save it to a file
plt.tight_layout()
plt.savefig("heap_sort_execution_time.png")
plt.show()
