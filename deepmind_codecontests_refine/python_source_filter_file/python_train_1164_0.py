n, k = map(int, input().split())
t = list(input())
i, m = 0, n // 2
if k > m: k = m + ((m + k) & 1)
print(k)
while k and i < n - 1:
    if t[i] == '4' and t[i + 1] == '7':
        k -= 1
        if i & 1 == 0: t[i + 1] = '4'
        else:
            t[i] = '7'
            i -= 2
    i += 1
print(''.join(t))