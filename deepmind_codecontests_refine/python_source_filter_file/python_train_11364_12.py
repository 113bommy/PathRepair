from math import *
n=int(input())
a=[]
b=list()
a=list(map(int,input().split(" ")))
for i in range(1,n):
	a[i]=a[i]//max(i,n-i-1)
print(min(a))