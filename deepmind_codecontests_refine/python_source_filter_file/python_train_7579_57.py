N, M = list(map(int, input().split()))
K = [int(input()) for i in range(N)]
K = sorted(K)
print(min([K[i+M-1]-K[i] for i in range(N-M+1)])