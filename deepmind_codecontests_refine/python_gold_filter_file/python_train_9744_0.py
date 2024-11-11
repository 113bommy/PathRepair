n,k = list(map(int,input().split()))
l   = list(map(int,input().split()))
print(max(0,(k*n-sum(l))*2-n))

