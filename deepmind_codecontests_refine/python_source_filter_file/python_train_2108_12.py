import math
d=[1,3]
e=[1]
for i in range(40):
    e.append(e[-1]*2)
for i in range(35):
    d.append(d[-1]+e[i+2])
for _ in range(int(input())):
    n=int(input())
    l=0
    for i in range(35):
        if d[i]>=n:
            l=i
            break
    if n==d[l]:
        print(l)
        f=[]
        for i in range(l):
            f.append(e[i])
        print(*f)
    else:
        l-=1
        if n-d[l]>=e[l]:
            print(l+1)
            f=[]
            for i in range(l+1):
                f.append(e[i])
            f[-1]-=d[l+1]-n
            print(*f)
        else:
            print(l+1)
            f=[]
            for i in range(l+1):
                f.append(e[i])
            f[-1]=0
            if (d[l]+e[l]-n)%2==0:
                f[-2]-=(d[l]+e[l]-n)//2
            else:
                f[-1]=1
                f[-2]-=(d[l]+e[l]-n)//2
            print(*f)




    
        

        