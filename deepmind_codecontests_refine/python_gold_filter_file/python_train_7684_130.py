a, b = map(int, input().split())
d = b - a - 1
print(d*(d+1)//2 - a)