import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# m=pow(10,9)+7
n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=0
if n>31:
	for j in a:
		ans+=j-1
# elif n>20:
# 	for j in range(n):
# 		ans+=abs(a[j]-pow(2,j))
else:
	if n==2:
		ans+=a[0]-1
	else:
		ans=10**18
		prev=10**18
		for i in range(1,100000):#int(math.ceil(math.log(10**9,n-1)))):
			cur=0
			for k in range(n):
				cur+=abs(a[k]-pow(i,k))
			# print(cur,i)
			if cur>prev:
				break
			prev=cur
			ans=min(ans,cur)
# print(pow(2,31)-10**9+7589934592)
# print(pow(3,19)-10**9)
# print(pow(3,20)-10**9+162261467)
# ans=0
# for j in range(21):
# 	if j>18:
# 		ans+=10**9-pow(2,j)
# 		continue
# 	ans+=pow(3,j)-pow(2,j)
print(ans)