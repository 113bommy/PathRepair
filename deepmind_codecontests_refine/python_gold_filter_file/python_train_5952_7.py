t=int(input())

for yo in range(t):
    n=int(input())
    l=input()
    l=l.split(" ")

    d1={}
    d2={}
    #f=[]
    for i in l:
        k=int(i)
        p=d1.get(k,-1)

        if(p==-1):
            d1[k]=1
            #d2[p]=1
            
        else:
            d1[k]+=1
            #d2[p]+=1
    ans=0
    for u,v in d1.items():
        if(d2.get(v,-1)==-1):
            d2[v]=1
        else:
            d2[v]+=1
    d3={}
    for u,v in d2.items():
        k=0
        i=0
        while(i<v):
            if(k>=u):
                break
            if(d3.get(u-k,-1)==-1):
                d3[u-k]=1
                ans+=u-k
                i+=1
            k+=1
    print(ans)