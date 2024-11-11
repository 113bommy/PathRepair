n, m = map(int,input().split())
a = input()
b = input()
w = 0
ans = 0
o = n - m
for i in range(m):
    if b[i] == '1': w += 1
    if i + o >= 0:
        if a[i + o] == '1':
            ans = (ans + pow(2, n - m + 1, 998244353) * w) % 998244353
print(ans)