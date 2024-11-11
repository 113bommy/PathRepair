n,k = map(int,input().split())
arr = list(map(int,input().split()))
print(max(0,n-sum(arr)))