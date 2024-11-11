for _ in range(int(input())):
    m=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    s=sum(b)
    sa=sum(a)
    pref_a=[a[0]]
    pref_b=[b[0]]
    for i in range(1,m):
        pref_a.append(pref_a[i-1]+a[i])
        pref_b.append(pref_b[i-1]+b[i])
    el=0
    while(s-b[m-1]<sa-pref_a[el]):
        el+=1 
        if(el>=m-1):
            el=m-1
            break
    if(el==0):
        print(sa-a[0])
    else:
        print(max(sa-pref_a[el],pref_b[el-1]))
        