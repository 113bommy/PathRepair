N, K = map(int, input().split())
H = list(map(int, input().split()))

print(sum(x >= K for x in H))