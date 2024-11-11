from sys import stdin
for i in range(int(input())):
	n,k=map(int,input().split())
	a=list(map(int,input().split()));v=['0']*n
	for i in range(1,n-1):
		if a[i-1]<a[i]>a[i+1]:v[i]='1'
	v=''.join(v)
	ans=ans1=v[:k-1].count('1')
	lst=0
	if ans:lst=max(0,v[:k-1].rindex('1')-k+3)
	for i in range(k,n):
		if v[i-1]=='1':ans1+=1
		if v[i-k+1]=='1':ans1-=1
		if ans1>ans:
			ans=ans1
			lst=i-k+2
	print(ans+1,max(0,lst))