t = int(input())
for i in range(t):
    n,a,b=map(int,input().split())
    s=input()
    p=[]
    p1=0
    p2=0
    for j in range(n):
        if s[j]=='0':
            p1+=1
            if p2!=0:
                p.append(p2)
            p2=0
        else:
            p2+=1
            if p1!=0:
                p.append(p1)
            p1=0
    if p1!=0:
        p.append(p1)
    if p2!=0:
        p.append(p2)
    et=0
    dld=0
    dls=1
    uk=0
    for j in range(len(p)):
        if s[uk]=='0':
            if et==0:
                if j==len(p)-1:

                    dld+=p[j]
                    uk+=p[j]
                    dls+=p[j]
                else:
                    et=1
                    dld+=p[j]+1
                    dls+=p[j]+1
                    uk+=p[j]
            elif et==1:
                if j==len(p)-1:
                    dld+=2+p[j]-1
                    dls+=p[j]
                    uk+=p[j]
                elif p[j]==1:
                    dld+=1
                    uk+=p[j]
                    dls+=2
                elif (4+p[j]-2)*a+(p[j]-1)*b<=p[j]*a+(p[j]-1)*2*b:
                    dld+=4+p[j]-2
                    dls+=p[j]+1
                    uk+=p[j]
                else:
                    dld+=p[j]
                    dls+=p[j]*2*b
                    uk+=p[j]
        else:
            dld+=p[j]
            dls+=p[j]*2
            uk+=p[j]
    print(dld*a+dls*b)

