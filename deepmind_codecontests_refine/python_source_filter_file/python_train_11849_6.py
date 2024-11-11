n = int(input())
s = list(input())
t = "abcdefghijklmnopqrstuvwxyz"
ans = 1

for i in range(n):
    ans *= (s.count(t[i]) + 1)

print((ans-1)%(10**9+7))