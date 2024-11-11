a, b, c = map(int, input().split())
x = 0
if a > b and a > c:
    max = a
    s1= b
    s2 = c
elif b > a and b > c:
    max = b
    s1 = a
    s2 = c
else:
    max = c
    s1 = a
    s2 = b

if max >= s1 + s2:
    print(abs(max - (s1 + s2 +1)))
else:
    print(0)