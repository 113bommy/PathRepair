
for _ in range(int(input())):
    b,p,f=map(int,input().split())
    h,c=map(int,input().split())
    s=0

    if c>h :
        while  f !=0 and b>1:
            s+=c
            b-=2
            f-=1
        while b >1 and p>0:
            s+=h
            b-=2
            p-=1
    else:
        while  p !=0 and b>1:
            p-=1
            b-=2
            s+=h 
        while b >1 and f>0:
            s+=c
            b-=2
            f-=1
    print(s)



