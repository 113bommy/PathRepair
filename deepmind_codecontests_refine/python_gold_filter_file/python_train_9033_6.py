n, k = map(int, input().split())
h = list(map(int, input().split()))
h.sort(reverse=1)
print(sum(h[k:]))