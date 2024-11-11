n = int(input())
d = n - len(input().rstrip('1'))
print(n if d == n else d + 1)
