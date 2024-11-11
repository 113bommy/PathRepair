n,y=map(int,input().split())
for i in range(n+1):
    for j in range(n+1-i):
        if 10000*i+5000*j==y-100*(n-i-j):
            print(i,j,n-i-j)
            exit()
else:
    print(-1,-1,-1)