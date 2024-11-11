import sys

q = int(sys.stdin.readline())
for line in sys.stdin:
    piles = [int(c) for c in line.split()]
    print(str(int(sum(piles) / 2)))
