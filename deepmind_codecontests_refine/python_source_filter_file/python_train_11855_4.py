i=lambda:map(int,input().split());n,m=i();a=[0]+[1]*n;b=[0,1]+[0]*n
for _ in[0]*m:x,y=i();a[x]-=1;a[y]+=1;b[y]|=b[x];b[x]&=a[x]
print(sum(b))