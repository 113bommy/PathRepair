from math import ceil
n, k = [int(c) for c in input().split()]
s = sum(int(c) for c in input().split())
print(max(0, ceil(2 * (n * (k - 0.5) - s))))
