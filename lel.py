import subprocess

def run_c_program(cmd, num, proc):
    input_str = f"{cmd} {num}\n"
    proc.stdin.write(input_str)
    proc.stdin.flush()

    output = proc.stdout.readline()
    print(output.strip())

def main():
    proc = subprocess.Popen(['./a.out'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)

    while True:
        command = input()
        number = int(input())
        run_c_program(command, number, proc)

    proc.stdin.close()
    proc.wait()

if __name__ == "__main__":
    main()

