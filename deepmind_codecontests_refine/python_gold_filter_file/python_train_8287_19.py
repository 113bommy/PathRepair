n = int(input())
a = int(input())
b = int(input())
c = int(input())
n -= 1
if n == 0:
    print(0)
elif n == 1:
    print(min(a, b))
elif n == 2:
    print(a + b + c - max(a, b, c))
else:
    if min(a, b, c) == c:
        print((n-1)*c + min(a, b))
    else:
        print(n * min(a, b, c))