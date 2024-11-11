t=int(input())
for _ in range(t):
    n=int(input())
    m=list(map(int,input().split()))
    m.sort()
    m1=0
    m2=0
    m3=0
    m1m=0
    m2m=0
    for i in m:
        m3=i//3
        if i==1:
            m1m=1
        if i==2:
            m2m=1
        if i%3==1:
            m1=1
        if i%3==2:
            m2=1
    if m[-1]%3==0 and m1==1 and m2==1:
        m3-=1
    elif m[-1]%3==1 and m1m==0 and m2==1 and m1==1:
        m3-=1
        i=n-2
        while 2>m[i+1]-m[i]>0:
            if m[i+1]-m[i]==1:
                m3+=1
                break
            elif m[i+1]-m[i]==0:
                i-=1
            if i==-1:
                break
                
    print(m1+m2+m3)
            
    
    
    
    
