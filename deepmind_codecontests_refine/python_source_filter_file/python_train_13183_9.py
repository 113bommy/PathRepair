R = lambda: map(int, input().split())
a = list(map(int, input()))
b = list(map(int, input()))
bn = int(''.join(map(str, b)))
res = int(''.join(map(str, sorted(a))))
if len(b) != len(a):
    print(''.join(map(str, sorted(a, reverse=True))))
else:
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i] < a[j] < b[i]:
                a[i], a[j] = a[j], a[i]
        tmp = int(''.join(map(str, a[:i + 1] + sorted(a[i + 1:], reverse=True))))
        res = max(res, tmp) if tmp < bn else res
        for j in range(i + 1, len(a)):
            if a[j] == b[i]:
                a[i], a[j] = a[j], a[i]
    print(res)