from sys import stdin
input=stdin.readline
n,k=map(int,input().split())
p=list(map(int,input().split()))
tot=n*k - (n) * (n - 1) // 2
prev=0
mult=1
mod=998244353
for i in range(len(p)):
    if p[i] > n - k:
        prev = i
        break
for i in range(i + 1, len(p)):
    if p[i] > n - k:
        mult *= i - prev
        prev = i
        mult %= mod
print(str(tot) + ' ' + str(mult))
