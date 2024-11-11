import sys
import collections as cc
import bisect as bi
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
pr=[]
N=10**6+3
ss=[0]*(N)
ss[0]=1
for i in range(2,N):
	if ss[i]==0:
		ss[i]=i
		pr.append(i)
		for j in range(2*i,N,i):
			ss[j]=i
n,=I()
l=I()
f={}
ans=0
an=[]
for i in range(n):
	f[l[i]]=i
for i in range(n):
	while l[i]!=i+1	:
		ans+=1
		now=f[i+1]
		dis=now-i+1
		temp=bi.bisect(pr,dis)
		temp=pr[temp-1]
		#print(l[i],i+1,temp)
		f[l[now]],f[l[now-temp+1]]=f[l[now-temp+1]],f[l[now]]
		l[now-temp+1],l[now]=l[now],l[now-temp+1]
		an.append([now+1,now-temp+2])
print(ans)
for i in an:
	print(*i)

