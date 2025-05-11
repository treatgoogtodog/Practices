import random

# Function to generate n integers and write them to a file
def generate_integers(n, filename):
    try:
        with open(filename, 'a') as file:
            for _ in range(n):
                # Generate a random integer
                number = random.randint(-100000, 100000)  # You can customize the range
                # Write the integer to the file
                file.write(f"{number}"+" ")
        print(f"Successfully wrote {n} integers to {filename}.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
if __name__ == "__main__":
    n = int(input("Enter the number of integers to generate: "))
    filename = "MedianOfSortedArray.inp"  # Change this to your desired file name
    generate_integers(n, filename)
    