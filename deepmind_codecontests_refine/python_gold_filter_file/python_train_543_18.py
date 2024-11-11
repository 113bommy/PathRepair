for _ in range(int(input())):
    n=int(input())
    c=0
    if n==1:
        c=0
    else:
        p=n//2
        q=n
        while(p>0):
            c+=((4*q)-4)*p;
            p-=1
            q-=2
    print(c)
        