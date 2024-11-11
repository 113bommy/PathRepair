n = int(input())
a = int(input())
b = int(input())
c = int(input())
s = 0
if n == 1:
    print(0)
else:
    if a>b:
        s += b
        n -= 1
        while n>1:
            if b>c:
                s += c
            else:
                s += b
            n -= 1
    else:
        s += a
        n -= 1
        while n>1:
            if a>c:
                s += c
            else:
                s += a
            n -= 1
print(s)