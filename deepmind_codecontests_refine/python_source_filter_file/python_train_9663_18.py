# D - We Love ABC
import sys
readline = sys.stdin.readline

S = list(str(readline().rstrip()))
print(S)
MOD = 10**9 + 7
a = 0
ab = 0
abc = 0
pat = 1
for s in S:
    if s == 'A':
        a = (a + pat) % MOD
    elif s == 'B':
        ab = (ab + a) % MOD
    elif s == 'C':
        abc = (abc + ab) % MOD
    else: # s == '?'
        tmpa = a
        tmpab = ab
        a = (3*a + pat) % MOD
        ab = (3*ab + tmpa) % MOD
        abc = (3*abc + tmpab) % MOD
        pat = (pat*3) % MOD

print(abc)