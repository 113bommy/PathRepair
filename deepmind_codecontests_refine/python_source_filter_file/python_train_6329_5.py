n, k = map(int, input().split())
aa = list(map(int, input().split()))

mod = 10**9+7

ans = 0

s = 0
count = [0 for _ in range(2000)]
for a in aa :
    s += sum(count[a:])
    count[a-1] += 1
ans = s*k%mod

s = 0
for i in range(2000) :
    s += sum(count[i+1:])
ans = (ans+s*k*(k-1)//2)%mod

print(ans)