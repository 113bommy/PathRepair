
t = int(input())

def ckeven(c):
    if c%2==0:
        return True
    else:
        return False

while t:
    t-=1

    r,g,b,w = map(int,input().split())

    if r == 0 or g == 0 or b == 0:

        cnt=0
        cnt += not ckeven(r)
        cnt += not ckeven(g)
        cnt += not ckeven(b)
        cnt += not ckeven(w)
        if cnt>=2:
            print('No')
        else:
            print('Yes')
        continue
    r=ckeven(r)
    g = ckeven(g)
    b = ckeven(b)
    w = ckeven(w)

    if r and g and b and w:
        print("Yes")
        continue
    if (r and g and not b and w) or (r and not g and b and w)or (not r and g and b and w)or(r and g and b and not w):
        print("Yes")
        continue
    if (r and not g and not b and not w) or (not r and g and not b and not w)or(not r and not g and b and not w)\
            or(not r and not g and not b):
        print("Yes")
        continue
    print("No")

