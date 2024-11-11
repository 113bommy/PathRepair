n,k = map(int,input().split())
for i in range(n+1,0,-1):
    if (n-i)*(n-i+1)//2-i==k:
        print(i)
        break