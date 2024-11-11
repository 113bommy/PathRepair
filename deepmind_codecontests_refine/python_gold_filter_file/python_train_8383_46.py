n,k=map(int,input().split())
S=n//k
p=10**9//k
for i in range(S,p+10):
    if k*i > n:
        print(k*i)
        break
