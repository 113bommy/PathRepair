import sys
import math
input=sys.stdin.readline
n,k=map(int,input().split(" "))
l=list(map(int,input().split(" ")))
for i in range(n):
	l[i]=(l[i],i)
z=sorted(l, key=lambda x:(-x[0],x[1]))
ans=0
arr=[]
m=(998244353)
for i in range(k):
	ans+=(z[i][0])%m
	arr.append(z[i][1])
z=1
ans=ans%m
arr.sort()
# print(arr)
for i in range(len(arr)-1):
	if(arr[i]!=arr[i+1]-1):
		d=arr[i+1]-arr[i]
		
		z=(z*(d%m))%m
z=z%m
print(ans,z)




