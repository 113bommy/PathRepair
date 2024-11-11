import sys
# from sortedcontainers import SortedList

max_int = 1000000007  # 10^9+7
min_int = -max_int

n, k = map(int, sys.stdin.readline().split())
a = [min_int] + list(map(int, sys.stdin.readline().split())) + [max_int * 2]
for i in range(n + 2):
    a[i] = a[i] - i
if k:
    b = list(map(int, sys.stdin.readline().split()))
    b.sort()
else:
    b = []

diaps = []
l = 0
for bb in b:
    diaps.append((l, bb))
    l = bb
diaps.append((l, n + 1))

# print(diaps)

out = 0
for l, r in diaps:
    if a[r] < a[l]:
        out = -1
        break

    if r - l > 1:
        sl = []
        for i in range(l + 1, r):
            if a[r] >= a[i] >= a[l]:
                if not sl:
                    sl.append(a[i])
                else:
                    ll = -1
                    rr = len(sl)
                    while rr - ll > 1:
                        m = (rr + ll) // 2
                        if sl[m] > a[i]:
                            rr = m
                        else:
                            ll = m
                    if rr == len(sl):
                        sl.append(a[i])
                    else:
                        sl[rr] = a[i]

        out += r - l - len(sl) - 1

print(out)
