n, p = map(int, input().split())
if n == 1 or p== 1:
    print(p)
    exit()
c2 = 0
while p%2 == 0:
    c2 += 1
    p//=2
c = 2**(c2//n)
i = int(p**(1/n))
if i%2 == 0:
    i -= 1
while i > 1:
    if p%(i**n) == 0:
        print(c*i)
        exit()
    else:
        i -= 2
print(c)
