N, K = map(int, input().split())
P = list(map(int, input().split())).sort()
print(sum(P[:K]))
