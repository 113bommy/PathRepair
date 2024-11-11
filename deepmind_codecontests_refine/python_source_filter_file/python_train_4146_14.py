from collections import Counter
if __name__ == "__main__":
    N=int(input())
    lista=list(map(int,input().split()))
    mii=Counter(lista)
    si=set(lista)
    listb=[i for i in si]
    listb.sort()
    ans=0
    while(len(listb)>1):
        x=listb.pop()
        if mii[x]>0:
            k=1
            while k<=x:
                k*=2
            y=k-x
            if x==y:
                ans+=mii[x]//2
            elif y<x and y in si:
                m=min(mii[x],mii[y])
                ans+=m
                mii[y]-=m
            mii[x]=0
    print(ans)