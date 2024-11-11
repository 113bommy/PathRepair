a,b = map(int, input().split())
c = a
while a >= b:
    c = c + a//b
    a = a//b
print(c)
        