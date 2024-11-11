a,b = input().split()
a = int(a)
b = int(b)
s = 1
while a < b:
    a *= 3
    b *= 2
    s += 1
print(s)