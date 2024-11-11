N, *a = map(int, open(0).read().split())
x = [a[i] - i - 1 for i in range(N)]
print(sum([abs(v - x[N // 2]) for v in x]))
