#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import Counter
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################

for ii in range(int(input())):
	arr = list(map(int , input().split()))
	arr.sort()
	theta = math.atan((arr[2]-arr[0])/arr[1])
	#print(theta,arr)
	print(math.floor(arr[1]/math.cos(theta)))








'''
# Wrap solution for more recursion depth
#submit as python3
import collections,sys,threading
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)



threading.Thread(target=solve).start()
'''
