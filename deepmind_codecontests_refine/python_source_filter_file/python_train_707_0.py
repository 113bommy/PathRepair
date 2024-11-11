m=float("INF")
sunukes=[]
for i in range(7,-1,-1):
    for j in range(1000,10,-1):
        #print(i,j)
        sunuke=j*(100**(2*i))-1
        s=str(sunuke)
        sn=0
        for k in range(len(s)):
            sn+=int(s[k])
        x=sunuke/sn
        #print(sunuke,x)
        if x<=m :
            m=x
            sunukes.append(sunuke)
for i in range(9,0,-1):
    sunukes.append(i)
sunukes=sunukes[::-1]
k=int(input())
#print(sunukes)
for i in range(k):
    print(sunukes[i])
