t = int(input())
z = []
p = True
for i in range(t):
    a,b,c,d,k = map(int,input().split()) # k - место в пенале
    x = 0
    y = 0
    w = 0
    t = True
    while t :
        t = False
        if a > x*c:
            x += 1
            t = True
        if b > y*d:
            y += 1
            t = True
        if k < x+y:
            w = 1
            t = False
    if w == 1:
        z.append(-1)
    else:
        z.append(str(x) + ' ' + str(y))
print(z)
for i in z:
    print(i)