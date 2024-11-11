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
for i in range(len(brr)):
	crr=copy.deepcopy(arr)
	crr.pop(i)
	if brr[i] in crr:
		ans+=1
print(len(arr)-ans)
