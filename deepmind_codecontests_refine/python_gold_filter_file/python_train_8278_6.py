n,m=map(int,input().split())
l=list(map(int,input().split()))
l1=list(map(int,input().split()))
l2=[]
l3=[]
su=sum(l)
def chek(N) :
    v=0
    
    for i in range(n) :
        d=max(0,N-l2[i])
        if d>0 :
            d-=1
            v+=l[i]-l3[i]
        v+=l[i]*d
    if v<=m :
        
        return False
    else :
        return True
def search():
    p = 0
    ost = 10000000001;
    while (p <= ost) :
        mid = (p + ost) // 2;
        if chek(mid) :
            ost = mid - 1
        else :
            p = mid + 1;
    return p       

            
            
for i in range(n) :
    l3.append(l1[i]%l[i])
    l2.append(l1[i]//l[i])

e=search()

if chek(e) :
    print(e-1)
else :
    print(e)

    
    
