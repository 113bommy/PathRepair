n, k = [int(x) for x in input().split()]
s = [0 for i in range(101)]
for i in range(n):
    s[len(input())] += 1
p = len(input())

ans = 0
for i in range(p):
    ans += s[i]

print((ans)//k*5 + (ans+1), (ans+s[p]-1)//k*5 + (ans+s[p]))
