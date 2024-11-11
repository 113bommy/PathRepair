n,k=map(int,input().split())
print(max(n%k,(k-n%k)%k))