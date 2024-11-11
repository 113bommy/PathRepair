[a, b] = map(int, input().split())
n = abs(a-b)
if n == 1:
    n = 0
if n == 2:
    n = 0
if n == 3:
    n = 1
if n == 4:
    n = 2
if n == 5:
    n = 2
if a < b:
    x = a + n
    if (b-a)%2 == 0:
        y = 1
    else:
        y = 0
    z = 7-b+n
elif a == b:
    x = 0
    y = 1
    z = 0
elif a > b:
    x = 7-a+n
    if (a-b)%2 == 0:
        y = 1
    else: 
        y = 0
    z = b+n
print(int(x), int(y), int(z))