import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]

# code goes here

n = iread()
sticks = viread()
best = None
for t in range(0,101):
	cost = 0
	for s in sticks:
		if s > t + 1:
			cost += s - (t + 1)
		elif s < t - 1:
			cost += (t - 1) - s
	if best is None or cost < best[1]:
		best = (t, cost)
print(*best)
