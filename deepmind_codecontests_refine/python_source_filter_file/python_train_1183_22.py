from random import randrange
n,k=map(int,input().split())
a=sorted(list(map(int,input().split())))
for i in range(len(a)):
    if k==1:
        x=max(a)
        y=randrange(0,max(a))
        print(x,"",y)
        break
    if k==n:
        x=randrange(0,len(a)-1)
        y=randrange(0,len(a)-1)
        print(x,"",y)
        break
    if k>n:
        print("-1")
        break
    if k <n:
        x=a[len(a)-k]
        y=a[len(a)-k]
        print(x,"",y)
        break
