# Author - Soumya Saurav
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
n , d = map(int , input().split())
arr = []

for i in range(n):
    m , s = map(int , input().split())
    arr.append([m,s])

ans = 0
arr.sort(key = lambda x : (x[0], -x[1]))
i = 0
j = 0
temp = 0
while j < n:

    while j < n and abs(arr[j][0] - arr[i][0]) < d:
        temp += arr[j][1]
        j += 1

    ans = max(ans , temp)

    while i < n and j < n and abs(arr[j][0] - arr[i][0]) >= d:
        temp -= arr[i][1]
        i += 1
print(ans)


'''
# Wrap solution for more recursion depth
for dx,dy in [[1,0],[0,1],[-1,0],[0,-1]]:
#submit as python3
import collections,sys,threading
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)



threading.Thread(target=solve).start()
'''
