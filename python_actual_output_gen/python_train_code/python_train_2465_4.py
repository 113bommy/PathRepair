n,m=map(int,input().split())
l,a=[0]*(n+1),0
for i in range(m):a,b,c=map(int,input().split());l[a]-=c;l[b]+=c
for i in range(n+1):a+=abs(l[i])if(l[i])<0else(0)
print(a)