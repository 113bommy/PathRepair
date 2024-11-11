from math import ceil
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    print(max(2, ceil(x / max(a))) if x not in a else 0)
    