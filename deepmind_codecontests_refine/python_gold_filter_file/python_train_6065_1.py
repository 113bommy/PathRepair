n, t, p = int(input()) + 1, list(map(int, input().split())), {}
for i in t:
    if i < n: p[i] = 1
print(n - len(p) - 1)