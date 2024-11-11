import itertools as it


n, a = int(input()), list(map(int, input().split()))
b = list(it.accumulate([int(c > 1) for c in a[::-1]]))[::-1]
print(sum([a[i] + b[i + 1] for i in range(n - 1)]) + a[-1])
