n = int(input())
a = sorted(list(map(int, input().split())))
base = 10**9 + 7
d = [1]
for i in range(n):
    d.append((2*d[-1]) % base)
print(1)
ans = 0
for i in range(1, len(a)):
    diff = a[i] - a[i-1]
    add = diff*(d[i]-1)*(d[n - i]-1) % base
    ans += add
    ans = ans % base
print(ans)