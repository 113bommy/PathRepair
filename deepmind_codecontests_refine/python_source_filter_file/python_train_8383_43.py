n,k=map(int,input().split())
p=10**9//k
for i in range(1,p+1):
    if k*i > n:
        print(k*i)
        break
