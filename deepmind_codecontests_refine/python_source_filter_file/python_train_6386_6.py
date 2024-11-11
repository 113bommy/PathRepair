n, t = int(input()), list(map(int, input().split()))
print(min(min(max(t[i], t[i + 1]) for i in range(1, n - 2)), t[0], t[n - 1]) if n > 1 else t)