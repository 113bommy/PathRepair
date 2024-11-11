n, a, b = map(int, input().split())
h = list(map(int, input().split()))

h.sort()
if h[n - a] - h[b - 1] < 2:
    print("0")
else:
    print(h[n - a] - h[b - 1])

