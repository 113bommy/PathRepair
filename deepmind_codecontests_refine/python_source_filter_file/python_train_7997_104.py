# APC 001: A – Two Integers
x, y = [int(s) for s in input().split()]
print(-1 if x % y == 0 else x * 2)