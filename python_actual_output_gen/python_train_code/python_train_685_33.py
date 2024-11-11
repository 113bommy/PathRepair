N, K = map(int, input().split())
tmp = N%K
print(min(N,K-tmp))