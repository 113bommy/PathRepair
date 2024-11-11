for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    ans=0
    pref=[0]*n
    pref2=[0]*n
    pref[0]=a[0]
    pref2[0]=b[0]
    for i in range(1,n):
        pref[i]=pref[i-1]+a[i]
        pref2[i]=pref2[i-1]+b[i]
    pref2.append(0)
    m=100000000
    for i in range(n):
        x=max(pref[-1]-pref[i],pref2[i-1])
        m=min(m,x)
    if n==1:
        print(0)
    else:
        print(m)
        
    
