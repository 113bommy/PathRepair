n,L,a=[int(i) for i in input().split()]
if n==0:
        print(L//a)
else:
        z=0
        c=0
        for i in range(n):
                t,l=[int(i) for i in input().split()]
                if (t-z)>=a:
                         c=c+(t-z)//a
                z=l
        c=c+(L-(t+l))//a
        print(c)
