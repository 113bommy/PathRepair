def lcm(a,b):
    return (a*b)//gcd(a,b)
def gcd(a,b):
    if(a%b==0):
        return b
    else:
        return gcd(b,a%b)
for _ in range(int(input())):
    a,b,q=list(map(int,input().split()))
    if(a<b):
        x=b
        y=a
    else:
        x=a
        y=b
    anslcm=lcm(x,y)
    mul=anslcm-x
    ans=[]
    for w in range(q):
        l,r=list(map(int,input().split()))
        if(a==b):
            ans.append(0)
        else:
            startdiv=l//anslcm
            endiv=r//anslcm
            temp=mul*(endiv-startdiv)
            virstart=startdiv*anslcm
            virend=endiv*anslcm
            tempo=l%anslcm
            if(tempo>=x):
                tem=(tempo-x)
                temp-=tem
            tempo=r%anslcm
            if(tempo>=x):
                tem=tempo-x+1
                temp+=tem
            ans.append(temp)
    for q in ans:
        print(q,end=' ')
    print()
