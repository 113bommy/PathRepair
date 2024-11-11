n = int(input())
a = [int(i) for i in input().split()]
fit1 = [2 * i for i in range(1, n // 2 + 1)]
fit2 = [2 * i - 1 for i in range(1, n // 2 + 1)]
print(min(sum([abs(a[i] - fit1[i]) for i in range(n // 2)]),sum([abs(a[i] - fit2[i]) for i in range(n // 2)])))

