n,k=map(int,input().split())
print(max(0,min(n-k//2,k//2-1+k%2)))