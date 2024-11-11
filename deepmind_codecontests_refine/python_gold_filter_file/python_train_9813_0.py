'''input
5
1 100
2 50
51 99
52 98
10 60
'''
from sys import stdin
import sys
from bisect import bisect_left, bisect_right
import copy
sys.setrecursionlimit(15000)


# main starts
n = int(stdin.readline().strip())
event = []
for _ in range(n):
	event.append(list(map(int, stdin.readline().split())))

event = sorted(event, key = lambda x : x[0])
count  = 0
cur_min = event[0][0]
cur_max = event[0][1]
for i in range(1, len(event)):
	if event[i][0] > cur_min and event[i][1] < cur_max:
		count += 1
	elif event[i][1] > cur_max:
		cur_max = event[i][1]
print(count)