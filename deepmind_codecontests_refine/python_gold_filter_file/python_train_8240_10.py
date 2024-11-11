import math
import sys

n = int(sys.stdin.readline().strip())
for i in range(n):
	piles = list(map(int, sys.stdin.readline().split()))
	piles = sorted(piles)
	alice = piles[1]
	bob = piles[0]
	rem = piles[2]
	print((alice + bob + rem) // 2)

