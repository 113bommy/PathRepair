from collections import Counter
from sys import stdin, stdout

n, x = map(int, stdin.readline().split(' '))
ass = list(map(int, stdin.readline().split(' ')))
cnts = Counter(ass)
r = -n if x == 0 else 0
for a in ass:
	r += cnts[a ^ x]
stdout.write(str(r) + '\n')
