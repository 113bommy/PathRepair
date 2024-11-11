p = input().split()
l = int(p[0])
r = int(p[1])

if r-l < 3:
    print(-1)
elif l % 2 == 0:
    print(l, l+1, l+2)
else:
    if r-l==3:
        print(-1)
    else:
        print(l+1,l+2,l+3)