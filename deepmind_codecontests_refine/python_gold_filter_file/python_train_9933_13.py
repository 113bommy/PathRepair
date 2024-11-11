n, k = [int(x) for x in input().split(' ')]
h = [int(x) for x in input().split(' ')]
s = sum(h[:k])
m = s
index = - 1
for i in range(n - k):
    s -= h[i]
    s += h[i + k]
    if s < m:
        m = s
        index = i
print(index + 2)