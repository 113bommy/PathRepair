n, m = [int(x) for x in input().split(' ')]
d = {}
for x in input().split(' '):
    d[int(x)] = 1
ansarr = []
i = 1
while m > 0:
    if i not in d:
        if m > i:
            m -= i
            ansarr.append(i)
        else:
            m = 0
    i += 1
print(len(ansarr))
if len(ansarr):
    print(' '.join(map(str, ansarr)))
