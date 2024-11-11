import sys

q = int(sys.stdin.readline())
for line in sys.stdin:
    piles = [int(c) for c in line.split()]
    print(str(sum(piles) // 2))
