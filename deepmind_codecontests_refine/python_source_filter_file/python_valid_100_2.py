mod = 10**9+7
mx = 2*10**5+2
fact, inv_fact = [0] * (mx + 1), [0] * (mx + 1)
fact[0] = 1

for i in range(mx):
    fact[i + 1] = fact[i] * (i + 1) % mod

inv_fact[-1] = pow(fact[-1], mod - 2, mod)
for i in reversed(range(mx)):
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod

for _ in range(int(input())):
    n = int(input())
    l = sorted(map(int,input().split()))
    if l[-1]-l[-2]>1:
        print(0)
        continue
    elif l[-1]==l[-2]:
        print(fact[n])
    else:
        k = l.count(l[-2])
        print((fact[n]-fact[n]*fact[k]*inv_fact[k+1])%mod)
