import os
import sys
import subprocess
from tqdm import tqdm

def main():
    sizes = [10, 20, 50, 100, 1000, 5000, 10000, 20000, 50000, 100000]
    # sizes = [4, 10]
    outputs = []
    filename = "./out.exe"
    for size in sizes:
        a = subprocess.run(["powershell", "-Command", f"python inputs.py {size} -i"], capture_output=False)
        completed = subprocess.run(["powershell", "-Command", f"cat sort_input.txt | {filename}"], capture_output=True)
        outputs += completed.stdout.decode('utf-8').split('\n')

    with open('output.txt', 'w') as file:
        file.writelines(sorted(outputs))
    for o in sorted(outputs):
        print(o)

if __name__ == "__main__":
    main()
