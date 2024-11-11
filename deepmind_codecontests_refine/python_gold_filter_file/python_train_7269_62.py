N,Y=map(int,input().split())
ans=-1,-1,-1
for i in range(N+1):
    for j in range(N+1-i):
            if 1<=N<=2000 and 10000*i+5000*j+1000*(N-i-j)==Y:
                ans=i,j,N-i-j
print(*ans)