i=lambda:map(int,input().split());n,m=i();l=[0,1]+[0]*n;c=[0]+[1]*n
for _ in[0]*m:x,y=i();l[y]=l[x];c[y]+=1;c[x]-=1;l[x]=c[x]and l[x]
print(sum(c[i]and l[i]for i in range(n+1)))