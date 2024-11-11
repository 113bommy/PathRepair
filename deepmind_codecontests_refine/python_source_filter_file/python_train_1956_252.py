N,K=map(int, input().split())
print(max([N%K,abs(N%K-K)]))