N = int(input())
s = input()
t = input()
res = 2*N
for i in range(N):
    if s[i:N] == t[0:N-i]:
        res = N+1
        break
print(res)