# APC 001: A – Two Integers
x, y = map(int, input().split())
print('-1' if x % y == 0 else x * y)