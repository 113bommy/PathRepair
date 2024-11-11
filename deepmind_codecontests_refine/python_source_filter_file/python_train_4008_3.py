n, w = [int(i) for i in input().split()]
lst = sorted([int(j) for j in input().split()])
h = min(lst[0], lst[n] // 2, w // (3 * n))
print(3 * h * n)
