n,k=map(int,input().split())
print(max(min((k+1)//2-1,n-k//2),0))