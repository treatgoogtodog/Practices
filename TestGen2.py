import random

# Function to generate n integers in ascending order and write them to a file
def generate_sorted_integers(n, filename, lower_bound, upper_bound):
    try:
        # Generate n random integers in the specified range
        numbers = [random.randint(lower_bound, upper_bound) for _ in range(n)]
        # Sort the numbers in ascending order
        numbers.sort()
        
        # Write the sorted numbers to the file
        with open(filename, 'a') as file:
            for number in numbers:
                file.write(f"{number} ")
        print(f"Successfully wrote {n} sorted integers to {filename}.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
if __name__ == "__main__":
    n = 1000  # Number of integers to generate
    filename = "MedianOfSortedArray.inp"  # Output file name
    lower_bound = -100000  # Lower bound of the range
    upper_bound = 100000   # Upper bound of the range
    generate_sorted_integers(n, filename, lower_bound, upper_bound)