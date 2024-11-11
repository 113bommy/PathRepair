# May the Speedforce be with us...
'''
for _ in range(int(input())):
arr=list(map(int,input().split()))
n,k=map(int,input().split())
n=int(input())
s=input()

from collections import defaultdict
d=defaultdict()

d=dict()
s=set()
s.intersection()
s.union()
s.difference()


problem statement achhe se padhna hai
age se bhi dekhna hai, piche se bhi dekhna hai
'''
from math import gcd,ceil
from collections import defaultdict as dd
def lcm(a,b):
	return (a*b)//gcd(a,b)
def inin():
	return int(input())
def inar():
	return list(map(int,input().split()))
def ar(element,size):
	return [element for i in range(size)]
def digitsum(num):
	su=0
	while(num):
		su+=num%10
		num//=10
	return su

n,t=input().split()
title=t[0]
ans=n[0]
for i in n[1:]:
	if i>=title:
		break
	ans+=i
ans+=title
print(ans)