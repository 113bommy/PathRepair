n, k = [int(x) for x in input().split()]
ns = [int(x) for x in input().split()]
b = max([x for x in ns if n % x == 0])
print(n // b)