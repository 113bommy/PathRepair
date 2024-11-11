D,N = map(int,input().split())
print(N*100**D if N != 100 else N*100**(D-1))