import sys
input = sys.stdin.readline
#from collections import deque

n = int(input())
inc = []
dec = []
inc_cnt = 0
dec_cnt = 0
for i in range(n):
	a, b = map(int, input().split())
	if a < b:
		inc.append((a, b, i + 1))
		inc_cnt += 1
	else:
		dec.append((a, b, i + 1))
		dec_cnt += 1
if inc_cnt > dec_cnt:
	print(inc_cnt)
	inc = sorted(inc, key = lambda x: -x[0])
	print([x[2] for x in inc])
else:
	print(dec_cnt)
	dec = sorted(dec, key = lambda x: x[0])
	print([x[2] for x in dec])