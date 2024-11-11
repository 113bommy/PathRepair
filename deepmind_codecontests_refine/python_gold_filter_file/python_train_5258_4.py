#!/usr/bin/python3

n, t = map(int, input().split())
a, b = input(), input()
k = len([1 for i, j in zip(a, b) if i != j])
if t < (k + 1) // 2:
    print(-1)
else:
    p = -1
    ans = ['0'] * n
    for i in range(n):
        if a[i] != b[i] and k > t:
            if p == -1:
                p = i
            else:
                ans[p] = a[p]
                ans[i] = b[i]
                p = -1
                k -= 2
                t -= 1
    for i in range(n):
        if a[i] != b[i] and ans[i] == '0':
            for v in 'abc':
                if v != a[i] and v != b[i]:
                    ans[i] = v
                    break
            t -= 1
    for i in range(n):
        if a[i] == b[i] and t:
            ans[i] = 'a' if 'a' != a[i] else 'b'
            t -= 1
        elif a[i] == b[i]:
            ans[i] = a[i]
    print(''.join(ans))
