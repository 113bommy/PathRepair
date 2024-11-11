def plus(a, b):
    c = ""
    i = len(a)-1
    arg = 0
    while i >= 0:
        k = (arg + ord(a[i]) + ord(b[i]) - 194)
        arg = k < 26
        i -= 1
        c = chr(k % 26) + c
    c = chr(1) * arg + c
    return c


def minus(a):
    c = ""
    arg = 0
    for q in a:
        c += chr(ord(q)//2 + arg*13)
        arg = ord(q) % 2
    if arg:
        c = c[:len(c)-1] + chr(ord(c[len(c)-1])+1)
    return c


n = int(input())

a1 = ""
i = 0
while i < n:
    a1 += "s"
    i += 1

c = minus(plus(input() ,input()))
c1 = ""
for q in c:
    c1 += chr(ord(q) + 97)

print(c1[len(c1)-n:])
