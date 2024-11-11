import sys;import math;from collections import deque;from bisect import bisect_left,bisect_right;I=sys.stdin.readline;II=lambda :int(I());IN=lambda x:map(int,x.split());L=lambda x:list(IN(x));M=1000000007;P=print;T=True;F=False
for _ in range(II()):
	n=II()
	a=L(I())
	d=[];l=[T]*(n+1)
	for i in range(n):
		k=l[a[i]]
		if(k==True):
			k=[i+1,i]
			l[a[i]]=k
		k[0]=max(k[0],i-k[1])
		k[1]=i
		#P(k)
	#P(l)
	for i in range(1,n+1):
		if(l[i]==True):
			continue
		d.append(i)
		l[i][0]=max(l[i][0],n-l[i][1])
	#P(d,"\t",l)
	k=n+1;res=[]
	for i in d:
		if(l[i][0]>=k):
			break
		res.extend([i]*(k-l[i][0]))
		k=l[i][0]
		if(k==1):
			break
	f=[-1]*(k-1)
	P(*f,end=" ")
	for i in range(n-k,-1,-1):
		P(res[i],end=" ")
	P()

