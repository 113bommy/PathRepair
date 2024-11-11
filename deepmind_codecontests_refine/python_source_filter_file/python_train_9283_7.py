z=int(input())
if z%4==0 :print("NO")
else:
    print("YES")
    p=3;o=1
    print(1,end=" ")
    for i in range(z-1):
        if p==3:o+=p;print(o,end=" ");p=1
        else:o+=p;print(o,end=" ");p=3
    p = 1;o = 2
    print(2, end=" ")
    for i in range(z - 1):
        if p == 1:o+=p;print(o,end=" ");p =3
        else:o+=p;print(o,end=" ");p = 1