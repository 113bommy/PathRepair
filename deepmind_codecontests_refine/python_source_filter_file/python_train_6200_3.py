
n=int(input())
l=list(map(int,input().split()))
d={}
k=0
for i in range(n) :
    
    for j in range(1,25) :
        m=2**j
        f=-1
        try :
            d[m-l[i]]
            f=0
        except KeyError :
            pass
        if f==0  :
            k+=d[m-l[i]]
    f=-1
    try :
        d[l[i]]
        f=0
    except KeyError :
        pass
    if f==0 :
        d[l[i]]+=1
    else :
        d[l[i]]=1
print(k)
            
