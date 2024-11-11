n = int(input())
w = [0] * n
h = [0] * n
s = 0
W, H = 0, 0
h1, h2 = 0, 0
for i in range(n):
    w[i], h[i] = map(int, input().split())
    W += w[i]
    H += h[i]
    if h[i] > h1:
        h2, h1 = h1, h[i]
    elif h1 > h[i] > h2:
        h2 = h[i]
for i in range(n):
    d = h1 if h[i] != h1 else h2
    print((W - w[i]) * d, end=" ")
