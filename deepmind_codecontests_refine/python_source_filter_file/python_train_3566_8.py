for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    ev=0
    od=0
    b=[]
    c=[]
    for i in range(n):
        if i%2==0:
            ev+=a[i]
        else:
            od+=a[i]
    for i in range(0,n-1,2):
        b.append(a[i+1]-a[i])
    for i in range(1,n-1,2):
        c.append(a[i]-a[i+1])
    ma=0
    cur=0
    for i in range(len(b)):
        cur+=b[i]
        if cur>ma:
            ma=cur
        if cur<0:
            cur=0
    ma2=0
    cur=0
    for i in range(len(c)):
        cur+=c[i]
        if cur>ma:
            ma2=cur
        if cur<0:
            cur=0
    
    print(ev+max(ma,ma2))