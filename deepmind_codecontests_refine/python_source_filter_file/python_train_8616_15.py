import math
k = int(input())
s = len(input())

mod = 10**9 + 7

m25 = [] # 25の階乗をmodで割ったあまりを記録する配列
m26 = [] # 26の階乗
m_n = [1] # 逆元を記録する
a = 1
b = 1

for i in range(k+1):
    m25.append(a)
    a *= 25
    a %= mod

for i in range(k+1):
    m26.append(b)
    b *= 26
    b %= mod

for i in range(2,k+s):
    x = mod % i
    y = mod // i
    c = - m_n[x-1] * y
    c %= mod
    m_n.append(c)

samu = 0
fc = 1
for i in range(k):
    sm = fc
    sm *= m25[i]
    sm *= m26[k-i]
    sm %= mod
    samu += sm

    fc *= (s + i)
    fc %= mod
    fc *= m_n[i]
    fc %= mod

sm = fc
sm *= m25[k]
sm %= mod
samu += sm

samu %= mod
print(samu)
