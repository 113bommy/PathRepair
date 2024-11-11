from flactions import gcd 
from collections import defaultdict

def to_irreducible(a, b):
    if a == 0:
        return [0, 1]
    GCD = gcd(a, b)
    return [a//GCD, b//GCD]

MOD = 10**9 + 7
N = int(input())
daiichi_dict = defaultdict(int)
daini_dict = defaultdict(int)
zero_cases = 0

for i in range(N):
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        zero_cases += 1
    elif a * b >=0 and b != 0:
        a, b = to_irreducible(abs(a), abs(b))
        daiichi_dict[(a,b)] += 1
    else:
        a, b = to_irreducible(abs(b), abs(a))
        daini_dict[(a,b)] += 1
        daiichi_dict[(a,b)] += 0


ans = 1 
for key, value_daiichi in daiichi_dict.items():
    value_daini = daini_dict[key]
    ans *= (2**value_daiichi + 2**value_daini -1)
    ans %= MOD
print((ans+zero_cases-1) % MOD)
