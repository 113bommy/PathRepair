import sys
# input = sys.stdin.buffer.readline
from collections import Counter
def I(): return(list(map(int,input().split())))
def sieve(n):
	a=[1]*n
	for i in range(2,n):
	    if a[i]:
	        for j in range(i*i,n,i):
	            a[j]=0
	return a
def calc(x):
	c=0
	n=len(arr)
	# print(arr)
	for i in range(n//2):
		if sumarr[i]!=x:
			m=max(arr[i],arr[n-i-1])
			if sumarr[i]<x:
				m=min(arr[i],arr[n-i-1])
				m+=x-sumarr[i]
				if m>k:c+=2
				else:c+=1
			else:
				m=max(arr[i],arr[n-i-1])
				m-=sumarr[i]-x
				if m<0:c+=2
				else:c+=1
	return c

for __ in range(int(input())):
	n,k=I()
	arr=I()
	sumarr=[0]*(n//2)
	for i in range(n//2):
		sumarr[i]=arr[i]+arr[n-i-1]
	# print(sumarr)
	c=Counter(sumarr)
	prefarr=[0]*(2*k+2)
	for i in range(n//2):
		a,b=max(arr[i],arr[n-i-1]),min(arr[i],arr[n-i-1])
		r=a+k
		l=b+1
		prefarr[l]+=1
		prefarr[r+1]-=1
		# prefarr[a+b]-=1
		# prefarr[a+b+1]+=1
	minans=n
 
	for i in range(1,2*k+1):
		prefarr[i]+=prefarr[i-1]
		minans=min(minans,prefarr[i]-c.get(i,0)+2*(n//2-prefarr[i]))
	# print(prefarr)
	print(minans)
	


