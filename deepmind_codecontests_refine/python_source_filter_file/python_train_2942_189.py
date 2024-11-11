#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import OrderedDict
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################

for ii in range(int(input())):
	n = int(input())
	if n == 1:
		print(1)
	else:
		print(n//2)







