t=int(input())
for s in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    i=1
    maxi,maxu,mini,d=0,0,999999999,0
    while(i<n):
        if(a[i]!=-1 and a[i-1]!=-1):
            d=a[i]-a[i-1]
            if(d<0):
                d=d*-1
                maxi=max(maxi,d)
        else:
            maxu=max(maxu,a[i],a[i-1])
            if(a[i]!=-1):
                mini=min(mini,a[i])
            elif(a[i-1]!=-1):
                mini=min(mini,a[i-1])
        i+=1
    if(mini==999999999):
        mini=0
    dif=maxu-mini
    if(dif>2*maxi):
        print(dif-(dif//2),end=' ')
        print((maxu+mini)//2)
    else:
        print(maxi,end=' ')
        print((maxu+mini)//2)