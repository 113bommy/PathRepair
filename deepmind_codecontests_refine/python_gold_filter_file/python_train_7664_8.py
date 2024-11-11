n=int(input())
d={}
for _ in range(n):
    a=list(input().split())
    name=a[0]
    cnt=int(a[1])
    bfr=a[2:]
    if name in d:
        for bf in bfr:
            s=d[name]
            x=set()
            for i in s:
                if bf.endswith(i):
                    x.add(i)                    
            s=s.difference(x)
            if not any(i.endswith(bf) for i in s):
                s.add(bf)
            d[name]=s
    else:
        d[name]=set()
        for bf in bfr:
            s=d[name]
            x=set()
            for i in s:
                if bf.endswith(i):
                    x.add(i)
            s=s.difference(x)
            if not any(i.endswith(bf) for i in s):
                s.add(bf)
            d[name]=s
print(len(d))
for i in d:
    print(i,end=' ')
    s=d[i]
    print(len(s),end=' ')
    for j in s:
        print(j,end=' ')
    print()
        
                
    
