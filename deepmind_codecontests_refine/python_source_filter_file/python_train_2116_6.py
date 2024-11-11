mod = int(1e9+7)
n,m=map(int,input().split())
sets = list(set() for i in range(m))
for i in range(n):
    s = input()
    for j in range(m):
        sets[j].add(s[j])
ans=1
for i in range(m):
    ans*=len(s[i])
    ans%=mod
print(ans)
