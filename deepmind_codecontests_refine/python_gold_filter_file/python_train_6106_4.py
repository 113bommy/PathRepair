l = [-int(1e9), int(1e9)]
r = [-int(1e9), int(1e9)]

n = int(input())
a = [int(x) for x in input().split(' ')]
b = [int(x) for x in input()]

sumb = sum(b[:3])

for i in range(4, n):
    maxa = max(a[i-4:i+1])
    mina = min(a[i-4:i+1])
    sumb = sumb + b[i-1] - (b[i-5] if i-5>=0 else 0)
    if b[i] == 1:
        if sumb == 4:
            r[0] = max(r[0], mina)
        elif b[i-1] == 0 and sumb == 0:
            l[0] = max(l[0], maxa+1)
    else:
        if sumb == 0:
            l[1] = min(l[1], maxa)
        elif b[i-1] == 1 and sumb == 4:
            r[1] = min(r[1], mina-1)

print('%d %d' % (l[0], r[1]))

def verify(a, b):
    for i in range(4, n):
        t = b[i-1]
        if min(a[i-4:i+1]) > r[1] and sum(b[i-4:i]) == 4:
            t = 0
        elif max(a[i-4:i+1]) < l[0] and sum(b[i-4:i]) == 0:
            t = 1
        assert(t == b[i])
#verify(a, b)