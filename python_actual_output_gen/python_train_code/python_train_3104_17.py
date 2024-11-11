H, K = map(int, input().split())
hp = list(map(input().split()))
hp.sort(reverse=True)
print(sum(hp[K:]))
