n, l, r, ql, qr = map(int, input().split())

w = list(map(int, input().split()))

answ = 0
first = 0
last = sum(w)

answ = last * r + len(w) * qr

for i in range(n):
    first += w[i]
    last -= w[i]
    tmp = first * l + last * r
    if i + 1 > n - i - 1:
        tmp += ql * (i + 1 - n + i + 1 - 1)
    elif i + 1 < n - i - 1:
        tmp += qr * (n - 2 * i - 3)
    answ = min(answ, tmp)

print(answ)
