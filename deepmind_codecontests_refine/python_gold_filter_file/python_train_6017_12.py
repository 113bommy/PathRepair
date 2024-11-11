n, m, v, p = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
a = a[::-1]

s = [0] * p
for i in range(p, n + 1):
    s.append(s[-1] + a[i - 1])
s = s[1:]

ans = 0
for i in range(1, n + 1):
    if i <= p:
        ans += 1
    else:
        if v - 1 <= p - 1:
            if a[i - 1] + m >= a[p - 1]:
                ans += 1

        else:
            if v - p <= n - i:
                if a[i - 1] + m >= a[p - 1]:
                    ans += 1
            else:
                if a[i - 1] + m < a[p - 1]:
                    continue
                elif a[i-1] * (i - p) >= m * (v - n) + s[i - 2]:
                    ans += 1

print(ans)
