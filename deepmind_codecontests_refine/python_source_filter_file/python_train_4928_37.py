
n, a, b = map(lambda t: int(t), input().split())
h = list(map(lambda t: int(t), input().split()))

h.sort()
x = h[b] - h[a]
if x < 0:
    x = 0
print (x)