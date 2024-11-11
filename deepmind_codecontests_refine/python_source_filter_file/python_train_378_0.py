n = int(input())
l = list(map(int, input().split()))
print(min(sum(abs(i - x) for i, x in zip(range(s, n + 1, 2), l)) for s in (1, 2)))