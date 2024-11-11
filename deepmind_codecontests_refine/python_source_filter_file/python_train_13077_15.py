a, b = map(int, input().split())
c = 1
if b - a < 5:
    for i in range(a+1,b+1):
        i %= 10
        c *= a
else:
    c = 10
print(c%10)