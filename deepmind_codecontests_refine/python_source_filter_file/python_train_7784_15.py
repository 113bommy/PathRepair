n,m=map(int,input().split())
for i in range(m):
    print(i+1,n-i-(i>=m/2) & ~n)