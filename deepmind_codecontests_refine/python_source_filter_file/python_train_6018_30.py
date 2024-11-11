d=[0]*13
d[0]=1
s=input()
for k,t in enumerate(s[::-1]):
    if t=='?':
        d2=[0]*13
        for i in range(10):
            u=i*pow(10,d,13)
            for i in range(13):
                d2[(i+u)%13]+=d[i]
    else:
        u=int(t)*pow(10,d,13)
        d2=[0]*13
        for i in range(13):
            d2[(i+u)%13]+=d[i]
    for i in range(13):
        d[i]=d2[i]%(10**9+7)
print(d[5])