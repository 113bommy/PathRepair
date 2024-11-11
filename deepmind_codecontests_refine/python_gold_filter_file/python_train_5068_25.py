import sys
import math
from collections import OrderedDict
def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def minput():   return map(int, input().split()) 
def listinput(): return list(map(int, input().split()))
n,b=minput()
l=listinput()
co=0
ce=0
count=0
ans=[]
for i in range(n-1):
	if l[i]%2==0:ce+=1
	else:co+=1
	if co==ce:ans.append(abs(l[i]-l[i+1]))
ans=sorted(ans)
for i in ans:
	if b-i>=0:
		b-=i
		count+=1
print(count)