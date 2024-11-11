mod = 998244353 
n,k = list(map(int,input().split()))
arr = list(map(int,input().split()))

t = {}
cnt = n
ans = 0

for i in range(k):
    t[cnt] = 0
    ans = ans+cnt
    cnt-=1
    
temp = []
for i in range(n):
    if arr[i] in t:
        temp.append(i)
# temp.sort()

diff = []
for i in range(1,len(temp)):
    diff.append(temp[i]-temp[i-1])
q = 1
for i in diff:
    q = ((q%mod)*(i%mod))%mod
print(ans,q)