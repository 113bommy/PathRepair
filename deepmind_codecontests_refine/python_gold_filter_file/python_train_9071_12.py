import sys
sys.setrecursionlimit(20000000)
input = sys.stdin.readline
mod = 10**9 + 7
yon = [4**i for i in range(10000)]
rui = [0]*(len(yon)+1)
for i in range(len(yon)):
    rui[i+1] = rui[i] + yon[i]
def sum_ans(x):
    if x == 0:
        return 0
    a = x.bit_length()
    ans = 0
    for i in range(a-1):
        if i %2 == 0:
           ki = i//2
           hazi = rui[ki]
           hazi = hazi*2+1
           ko = 4**ki
           ans += (hazi+hazi+(ko-1)*2)*ko//2
           ans %= mod
        else:
           ki = i//2
           hazi = rui[ki]*2
           hazi = hazi*2+2
           ko = (4**ki)*2
           ans += (hazi+hazi+(ko-1)*2)*ko//2
           ans %= mod
    x -= (2**(a-1)-1)
    if a%2 == 1:
        ki = a//2
        hazi = rui[ki]
        hazi = hazi*2+1
        ans += (hazi+hazi+(x-1)*2)*x//2
        ans %= mod
    else:
        ki = (a-1)//2
        hazi = rui[ki]*2
        hazi = hazi*2+2
        ans += (hazi+hazi+(x-1)*2)*x//2
        ans %= mod
    return ans
n,m = map(int,input().split())
print((sum_ans(m)+mod-sum_ans(n-1))%mod)