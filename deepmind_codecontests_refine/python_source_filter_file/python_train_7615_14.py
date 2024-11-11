import sys

def main():
    _ = int(sys.stdin.readline().rstrip())
    lines = sys.stdin.read().split("\n")
    for line in lines:
        if len(line) < 3:
            continue
        n, k = [int(x) for x in line.split(" ")]
        i = 0
        while n > 0:
            if n % k == 0:
                i += 1
                n = n / k
            else:
                m = n % k
                n -= m
                i += m
        print(i)

main()
