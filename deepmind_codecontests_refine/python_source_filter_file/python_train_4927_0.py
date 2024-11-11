for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    d=dict()
    lal=dict()
    c=0
    for i,j in enumerate(a):
        d[j]=i+1
        lal[j]=True
    for i in range(1,int(n**0.5)+1):
        if lal.get(i,False):
            start= i+1
            while start*i<=2*n:
                if start==i:
                    start+=1
                    continue
                if lal.get(start,False):
                    if d[start]+d[i]==i*start:
                        c+=1
                start+=1
    print(c)