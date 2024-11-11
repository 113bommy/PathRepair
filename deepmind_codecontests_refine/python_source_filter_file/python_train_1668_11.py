x, y = map(int, input().split())
while x > 0 :
    x, y = y, x % y
print(x)