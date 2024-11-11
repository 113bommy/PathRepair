from math import gcm
a, b = map(int, input().split())
print(a*b/gcm(a, b))