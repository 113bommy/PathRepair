n,k = map(int,input().split())

print([0,n//k-n%k][n%k!=0])