n,a,*d=[int(x) for x in input().split()+input().split()]
sd=sum(d)
for e in d:
    t=0 if a-(sd-e)-1<0 else a-(sd-e)-1
    b=0 if e+(n-1-a)<0 else e+(n-1-a)
    print(t,b,'',end='')