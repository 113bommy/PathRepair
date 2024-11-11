#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import OrderedDict
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

#input = sys.stdin.readline

########################################
mydic = {2 : 2, 3:3, 4:233, 5:5, 6:53, 7:7, 8:7222, 9 : 7332}
n = int(input())
s = input()
count = defaultdict(int)

for i in s:
	#print(i,count)
	count[int(i)]+=1

count = sorted(count.items(), key = lambda x : x[1], reverse = True)
#print(count)
ans = ""
for k,v in count:
	if k == 1 or k == 0:
		continue
	ans+=str(mydic[k])*v
ans = sorted(list(ans), key = lambda x: int(x),reverse = True)
print("".join(ans))






