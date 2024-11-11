from itertools import combinations
while True:
    n, x = map(int, input().split())
    if n == x == 0:
        break
    print(sum(a + b + c == x for a, b, c in combinations(range(1, n + 1), 3))

