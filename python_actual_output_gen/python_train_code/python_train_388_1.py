n = int(input())
arr = [int(x) for x in input().split(' ')]
a, b = [min(arr.index(1), arr.index(n)), max(arr.index(1), arr.index(n))]
print(b - a - 1 + max(a, n - b))