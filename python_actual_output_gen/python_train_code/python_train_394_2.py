MOD = 998244353

n, k = map(int, input().split())
left=[]
right=[]
for _ in range(k):
    l,r=map(int, input().split())
    left+=[l]
    right+=[r]
pref = [0,1]

for i in range(n-1):
    new = 0
    for j in range(k):
        new += pref[max(0,i+2-left[j])] - pref[max(0,i+1-right[j])]
        #print(pref[max(0,i+2-left[j])], pref[max(0,i+1-right[j])])
    pref.append((pref[-1] + new) % MOD)
print(new)
