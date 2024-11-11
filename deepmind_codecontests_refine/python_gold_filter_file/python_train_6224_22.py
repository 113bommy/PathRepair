S = input()[::-1]
MOD = 2019

r = 0
C = [0 for _ in range(MOD)]
C[0] = 1

for i,s in enumerate(S):
    r += int(s)*pow(10,i,MOD)
    r %= MOD
    C[r] += 1

a = 0
for c in C:
    a += c*(c-1)/2

print(int(a))
