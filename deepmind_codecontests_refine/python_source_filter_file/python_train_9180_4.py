import math as mt
import collections as cc
import sys
input=sys.stdin.readline
I=lambda:set(map(int,input().split()))
n,=I()
s=list(input())
tf=0
l=1
r=1
for i in range(n):
	for j in range(i+1,n):
		ans=0
		s[i],s[j]=s[j],s[i]
		ch=0
		cnt=0
		cm=0
		for k in s:
			if k=='(':
				ch+=1
			else:
				ch-=1
			if ch<cm:
				cm=ch
				cnt=1
			elif ch==cm:
				cnt+=1
		if ch==0 and cnt>tf:
			
			tf=cnt
			l=i+1
			r=j+1
		s[i],s[j]=s[j],s[i]
print(tf)
print(l,r)
