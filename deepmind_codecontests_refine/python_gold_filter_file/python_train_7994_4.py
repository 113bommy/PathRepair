from itertools import accumulate

n = int(input())
a = sorted(tuple(map(int, input().split()))[::-1] for _ in range(n))
c, d = zip(*a)
print('YNeos'[any(x < y for x, y in zip(c, accumulate(d)))::2])
