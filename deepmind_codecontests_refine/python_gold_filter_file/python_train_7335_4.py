from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int, stdin.readline().split()))
for _ in range(1):#nmbr()):
    a=[]
    b=[]
    x=nmbr()
    last=0
    for i in range(x):
        n=nmbr()
        if n>0:
            if i==x-1:
                last=1
            a+=[n]
        else:b+=[-n]
    sa=sum(a)
    sb=sum(b)
    if sa>sb:print('first')
    elif sb>sa:print('second')
    else:
        na=len(a)
        nb=len(b)
        p=p1=f=s=0
        while p<na and p1<nb:
            if a[p]>b[p1]:f=1;break
            elif a[p]<b[p1]:s=1;break
            p+=1
            p1+=1
        if (f==s==0):
            print('first' if last else 'second')
        elif f:print('first')
        else:print('second')