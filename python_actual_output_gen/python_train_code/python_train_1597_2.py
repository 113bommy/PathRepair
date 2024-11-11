w,h= map(int, input().split())
u1,d1= map(int, input().split())
u2,d2= map(int, input().split())

while h!=0:
    w=w+h
    if h==d1:
        if w>u1:
            w=w-u1
        else:
            w=0
    elif h==d2:
        if w>u1:
            w=w-u2
        else:
            w=0
    h=h-1

print(w)