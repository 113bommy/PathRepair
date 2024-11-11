l = input().split()
a = int(l[0])
b = int(l[1])

e = max(a, b)
r = min(a, b)
d = format(e, 'b')
c = 0
print(d)
t = 0
j = 0
x = 0
if a != b:
    for i in range(len(d), 0 + j, -1):
        c += 2 ** (i - 1)
    k = c
    while c ^ r < r or c ^ e > e:
        c = 0
        for i in range(len(d)-j, 0, -1):
            c += 2**(i-1)
        j += 1

else:
    c = 0


print(c)

