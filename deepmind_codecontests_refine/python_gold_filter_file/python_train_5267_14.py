def name(n):
    if n < 26:
        return chr(n + ord('A'))
    else:
        return chr(n - 26 + ord('A')) + 'a'


n, k = tuple(map(int, input().split()))
data = list(map(lambda x: x == 'YES', input().split()))

res = []
for i in range(k-1):
    res.append(name(i))
for i in range(k - 1, n):
    if data[i - k + 1]:
        res.append(name(i))
    else:
        res.append(res[i-k+1])
print(' '.join(res))
