k = int(input())
d = int(input())

li = list(map(int,(list(str(k)))))
leng = len(li)
mod = 10**9+7

dp1 = [0 for _ in range(d)]
dp2 = [0 for _ in range(d)]

mm1 = li[0]
for i in range(mm1):
    dp2[i%d] += 1

for i in range(1,leng):
    for j in range(0,10):
        for l in range(d):
            #既にk以下であることが確定
            dp1[(l+j)%d] += dp2[l]
            dp1[(l+j)%d] %= mod

        #上からi桁目でk以下が確定
        if j<li[i]:
            dp1[(mm1+j)%d] += 1
            dp1[(mm1+j)%d] %= mod
    #print(dp1,dp2)
    mm1 = (mm1+li[i])%d
    dp2 = [dp1[i] for i in range(d)]
    dp1 = [0 for _ in range(d)]
dp2[sum(li)%d]+=1
print((dp2[0]-1)%mod)   






