n = int(input())
a = int(input())
b = int(input())
c = int(input())

if n == 1:
    print(0)
else:
    m = min([a, b, c])
    if m == c:
        print(min(a, b) + m * (n - 2))
    else:
        print(m + (n - 1))
