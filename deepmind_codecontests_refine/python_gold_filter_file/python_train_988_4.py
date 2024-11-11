n, bx = map(int, input().split())
x = 0
xdigits = [int(x) for x in input().split()]
for i in reversed(range(n)):
    x += xdigits[n-i-1]*bx**i
m, by = map(int, input().split())
y = 0
ydigits = [int(y) for y in input().split()]
for i in reversed(range(m)):
    y += ydigits[m-i-1]*by**i
if x > y:
    print(">")
elif x < y:
    print("<")
else:
    print("=")
