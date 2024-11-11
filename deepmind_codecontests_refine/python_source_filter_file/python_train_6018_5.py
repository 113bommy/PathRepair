mod=10**9+7
s=input()
dp1=[1]+[0]*12
for i in range(len(s)):
    dp2=[0]*13
    if s[i]!='?':
        p=int(s[i])
        for j in range(13):
            dp2[(j*10+p)%13]+=dp1[j]
    else:
        for p in range(10):
            for j in range(13):
                dp2[(j*10+p)%13]+=dp1[j]
    dp1=[dp2[j]%mod for j in range(13)]
print(dp1[5])
