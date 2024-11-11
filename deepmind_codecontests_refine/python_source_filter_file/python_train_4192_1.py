def sol():
    x,y=map(int,input().split())
    s=sorted(list(map(int,input().split())))
    z=list(map(int,input().split()))
    s.reverse()
    res=sum(s[:y])
    
    for n in range(z.count(1)):
        res+=s[n]
    tem=s[y:]
    v=[n-1 for n in z]
    v.sort()
    v.reverse()
    cur=0
    n=0
    while n<len(v):
        if v[n]==0:

            n+=1
            continue
        res+=tem[cur+v[n]-1]
        cur+=v[n]
        n+=1
        

    print(res)



for n in range(int(input())):
    sol()