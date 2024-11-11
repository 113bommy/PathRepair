D,T,S = map(int, input().split())
print('Yes' if D//(S-D+1) <= T else 'No')