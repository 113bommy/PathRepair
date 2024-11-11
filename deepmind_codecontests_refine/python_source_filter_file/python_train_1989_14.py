import sys
import math
lines = []
for line in sys.stdin:
	lines.append(int(line))
income = lines[1]
peoples = lines[2:]
top = max(peoples)
flop = max(top, math.floor(sum(peoples) + income / lines[0]))
print('{} {}'.format(flop, top + income))
