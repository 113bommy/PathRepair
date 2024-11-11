n,m=map(int,input().split())
ans=0
for i in range(1,m+1):
    for j in range(1,m+1):
        if ( i*i %m + j*j % m) % m ==0:
           ans+=(((n+m-i)//m)*((n+m-j)//m));
print(ans)
