import math
lt = list(input().split())
a, x, y = int(lt[0]), int(lt[1]), int(lt[2])
mx = 5 * a
fn = True
D=[3,5]
D1={1:1,2:2,4:5}
if y <= 0 or y % a == 0:
    fn = False
else:
    bx=math.ceil(y/a)
    if bx>=3:
        if bx%2==0:
            if x>=(a/2) or x<=(-a/2):
                fn=False
            else:
                rs=bx+int(bx/2)-1
        else:
            if x>=a or x<=(-a) or x==0:
                fn=False
            else:
                q=(((bx-3)/2)+1)*3
                if x>0:
                    rs=q+1
                else:
                    rs=q
    else:
        if x>=(a/2) or x<=(-a/2):
            fn=False
        else:
            rs=bx

if fn:
    print(rs)
else:
    print(-1)
