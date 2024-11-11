from sys import stdin
input = stdin.readline
def nCr(n,r):
    return fact[n]*(inv[n-r]%M)*(inv[r]%M)
M = 1000000007
k = int(input())
s = len(input())
t = k+s
fact = [1]
p25 = [1]
for i in range(1,t+1):
    fact += [(fact[-1] * i)%M]
    if i<=k:
        p25  += [(p25[-1] * 25) % M]

inv = [1]*(t+1)
inv[t] = pow(fact[t], M-2, M)
for i in range(t-1, -1, -1):
    inv[i] = inv[i+1] * (i+1) % M


res = 0
for i in range(k+1):
    res+=nCr(t,t-i)*p25[i]
    res%=M
print(res)