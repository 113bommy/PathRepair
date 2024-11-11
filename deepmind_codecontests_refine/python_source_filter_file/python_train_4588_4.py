from itertools import combinations
while True:
    n, x = map(int, input().split())
    if n == x == 0:
        break
    print(len(1 for a, b, c in combinations(range(1, n + 1), 3) if a + b + c == x))

