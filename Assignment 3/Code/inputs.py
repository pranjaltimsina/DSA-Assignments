import os
import sys
import subprocess
import random
import datetime

def main(args: list, len_args: int)-> None:
    random.seed(datetime.datetime.now)
    if (len_args >= 2):
        MAX: int = int(args[1])
    else:
        MAX: int = 2000

    INPUT_FILE_NAME = "sort_input.txt"

    numbers: list = [str(MAX)+'\n']
    for i in range(MAX):
        numbers.append(str(random.randint(0, 500000)) + '\n')


    with open(INPUT_FILE_NAME, 'w') as file:
        file.writelines(numbers)

    if (len_args == 3 and args[2] == "-i"):
        sys.exit()

    print(f"\nRunning with {MAX} inputs:\n")
    for filename in os.listdir(os.getcwd()):
        if filename.endswith(".exe"):
            print(filename[:-4].title(), "sort:")
            completed = subprocess.run(["powershell", "-Command", f"cat {INPUT_FILE_NAME} | ./{filename}"], capture_output=True)
            print(completed.stdout.decode('utf-8'))

if __name__ == "__main__":
    main(sys.argv, len(sys.argv))
