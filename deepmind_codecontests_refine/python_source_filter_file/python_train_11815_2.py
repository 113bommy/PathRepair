n, a = map(int, input().split())
d = list(map(int, input().split()))
b = [0 for i in d]
s = sum (d)
if n == 1:
    print (d[0] - 1)
else:
    for i in range(len(d)):
        if s - d[i] < a:
            b[i] += a - s + d[i] - 1
        if d[i] >= a - n + 1:
            b[i] += d[i] - a + 1
    print (*b)