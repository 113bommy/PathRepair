mod = int(1e9+7)
stair = [1]
for i in range(1,2001):
    stair.append(stair[i-1]*i%mod)
def comb(stair,n,r):
    return (stair[n]//(stair[n-r]*stair[r]))%mod

n,k = map(int,input().split())
for i in range(1,k+1):
    ans = comb(stair,n-k+1,i) * comb(stair,k-1,i-1)
    print(ans%mod)