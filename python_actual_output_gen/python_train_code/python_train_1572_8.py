a = input() + input()
a, b = (ord(a[i]) - ord(a[i + 2]) for i in(0, 1))
print(max(a, -a, b, -b))
while a != 0 and b != 0:
    r = ''
    if a < 0:
        r = 'U'
        a += 1
    if a > 0:
        r = 'D'
        a -= 1
    if b < 0:
        r += 'R'
        b += 1
    if b > 0:
        r += 'L'
        b -= 1
    print(r)