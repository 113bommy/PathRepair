n, k = map(int, input().split())
t = k // n
print(t + (1 if k*n != t else 0))
