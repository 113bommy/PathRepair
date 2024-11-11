N, K = map(int, input().split())
h = list(map(int, input().split()))
print(sum(K <= e for e in h))