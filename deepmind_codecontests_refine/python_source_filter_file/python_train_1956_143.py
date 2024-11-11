n,k = map(int,input().split())
print(max(abs(n%k-k),n%k))