#http://codeforces.com/contest/961/problem/B
#solved

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
t = list(map(int, input().split()))
add = 0
out = 0
s = [0]


for r in range(n):
    if t[r] == 0:
        s.append(s[r] + a[r])
    else:
        s.append(s[r])


if t[-1] == 0 and a[-1] > s[-2]:
    add = a[-1]


for i in range(n):
    if i <= (n - k) + 1:
        try:
            add = max(add, s[i + k] - s[i])

        except:
            add = max(add, s[-1] - s[i])

    if t[i] == 1:
        out += a[i]

print(out + add)