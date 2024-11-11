n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

def f(l):
    s = sum(l)
    sume = [s for i in range(n)]
    s3 = [0 for i in range(n)]
    ts = 0
    for i in range(1, n):
        sume[i] = sume[i - 1] - l[i - 1]
        ts += i * l[i]
        s3[n - i - 1] = s3[n - i] + i * l[n - i - 1]
    s2 = [ts for i in range(n)]
    for i in range(1, n):
        s2[i] = s2[i - 1] - (i - 1) * l[i - 1]
    return sume, s2, s3

a1, a2, a3 = f(a)
b1, b2, b3 = f(b)

best = 0
curr, t = 0, 0
for i in range(n):
    if i % 2 == 0:
        pot = curr + t * a1[i] + a2[i] - i * a1[i] +\
                (t + n - i) * b1[i] + b3[i]
    else:
        pot = curr + t * b1[i] + b2[i] - i * b1[i] +\
                (t + n - i) * a1[i] + a3[i]
    best = max(best, pot)
    if i % 2 == 0:
        curr += t * a[i] + (t + 1) * b[i]
    else:
        curr += t * b[i] + (t + 1) * a[i]
    t += 2
print(max(best, curr))
