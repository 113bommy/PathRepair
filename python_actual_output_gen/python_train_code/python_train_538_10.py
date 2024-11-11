a = sorted(map(int, input().split()))
p = ((0, 1), (1, 2), (2, 3), (3, 4), (0, 2), (1, 3), (2, 4))
print(sum(a) - max(0 if a[i] == a[j] else (j - i + 1) * a[i] for i, j in p))