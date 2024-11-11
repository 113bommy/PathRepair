n, w = list(map(int, input().split()))
l = list(map(int, input().split()))
mus = [0] * n
mus[0] = l[0]
for i in range(1, n):
    mus[i] = mus[i - 1] + l[i]
if max(mus) >= 0:
    if min(mus) >= 0:
        print(max(0, w + 1 - max(mus)))
    else:
        print(max(0,(w + 1) - max(mus) + min(mus)))
else:
    print(max(0, w + 1 - abs(min(mus))))