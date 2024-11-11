H,N = map(int,input().split())
lsA = list(map(int,input().split()))
print('Yes' if H <= sum(lsA) else 'No')