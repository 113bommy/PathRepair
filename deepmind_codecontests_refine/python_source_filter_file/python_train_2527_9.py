n = int(input())
S = list(input())

mod = 10**9 + 7

dpa = [0]*(2*10**5+10)
dpc = [0]*(2*10**5+10)

hatena_count = 0
pow3 = [1]*(2*10**5+10)

for i in range(1, 10**5+10):
    pow3[i] = pow3[i-1]*3 % mod

for i in range(n):
    if S[i] == "a":
        dpa[i+1] = (dpa[i] + pow3[hatena_count]) % mod
    elif S[i] == "?":
        dpa[i+1] = (3*dpa[i] + pow3[hatena_count]) % mod
        hatena_count += 1
    else:
        dpa[i+1] = dpa[i]

S.reverse()

hatena_count = 0
for i in range(n):
    if S[i] == "c":
        dpc[i+1] = (dpc[i] + pow3[hatena_count]) % mod
    elif S[i] == "?":
        dpc[i+1] = (3*dpc[i] + pow3[hatena_count]) % mod
        hatena_count += 1
    else:
        dpc[i+1] = dpc[i]

ans = 0
for i in range(1, n - 1):
    if S[i] == "b" or S[i] == "?":
        ans += dpa[n-1-i]*dpc[i]
        ans %= mod
print(ans)



