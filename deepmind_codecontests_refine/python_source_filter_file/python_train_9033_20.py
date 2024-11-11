H, K = map(int, input().split())
hp = list(int, map(input().split()))
hp.sort(reverse=True)
print(sum(hp[K:]))
