
import sys
import math
import itertools
from collections import defaultdict

n = int(sys.stdin.readline().rstrip())
inp = [int(x) for x in sys.stdin.readline().rstrip().split()]

divs = set()

for i in range(1, int(n**0.5) + 1):
	if n%i == 0:
		if i >= 3:
			divs.add(i)
		if n/i >= 3:
			divs.add(int(n/i))

divs = list(divs)
divs.sort()

maxn = 0
for d in divs:
	for i in range(0,d):
		tot = sum(inp[x] for x in range(n)[i::d])
		maxn = max(tot, maxn)

print(maxn)




