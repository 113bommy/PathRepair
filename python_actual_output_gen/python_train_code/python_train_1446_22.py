t=int(input())
for _ in range(t):
    n=int(input())
    p=list(map(int,list(input())))
    if 1 in p:
        if p[0]==1 or p[-1]==1:
            print(2*n)
        else:
            z=p.index(1)
            p.reverse()
            z1=p.index(1)
            print(2*(max(z,z1)+1))
    else:
        print(n)