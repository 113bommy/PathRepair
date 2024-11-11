n,k = map(int,input().split())
for i in range(1,n+1):
    if (n-i)*(n-i+1)//2-i==k:
        print(i)
        break