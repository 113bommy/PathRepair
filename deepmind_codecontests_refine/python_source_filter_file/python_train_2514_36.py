'''input
2
33
1 1 1 1 1 1 1 1 1
'''
from sys import stdin, stdout, maxsize
import math
from copy import deepcopy
from collections import defaultdict
import heapq

# main starts
n = int(stdin.readline().strip())
string = list(stdin.readline().strip())
string = list(map(int, string))
mymap = list(map(int, stdin.readline().split()))
flag = 0
for i in range(n):
	if flag == 0 and string[i] <= mymap[string[i] - 1]:
		string[i] = mymap[string[i] - 1]
		flag = 1
	elif flag == 1:
		if string[i] <= mymap[string[i] - 1]:
			string[i] = mymap[string[i] - 1]
		else:
			break
for i in string:
	print(i, end= '')		