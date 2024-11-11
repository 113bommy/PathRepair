#!/usr/bin/python

n, k=input().split()
n=int(n)
k=int(k)
ming=1-(n==k | k==0)
if(n//3>=k):
	maxg=2*k
else:
	maxg=2*(n//3)-(k-n//3)+(n%3)
print(ming, maxg)