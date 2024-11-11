a,b = map(int, input().split())
s = a
while a >= b:
    a =  a // b
    s += a
print(int(s))