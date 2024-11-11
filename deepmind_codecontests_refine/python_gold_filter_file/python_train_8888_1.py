from bisect import*
import sys
input=sys.stdin.buffer.readline
import copy

n=int(input())
arr=[]
brr=[]
while n:
	n-=1
	a,b=map(int,input().split())
	arr.append(a)
	brr.append(b)
ans=0
for i in range(len(arr)):
	crr=copy.deepcopy(brr)
	crr.pop(i)
	if arr[i] in crr:
		ans+=1
print(len(arr)-ans)
