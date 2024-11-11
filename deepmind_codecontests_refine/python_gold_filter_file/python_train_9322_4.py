def BS(a, l , r, x):
    global g
    mid = l + (r - l) // 2
    if(r >= l):
        if (a[mid] > x):
            g = mid
            return BS(a, l, mid - 1, x)
        else:
            return BS(a, mid + 1, r, x)
    return g

n = int(input())
a = [int(v) for v in input().split()]
a.sort()
q = int(input())
for i in range (0, q):
    m = int(input())
    g = 0
    if(m >= a[n - 1]):
        print(len(a))
    else:
        print(BS(a, 0, len(a) - 1, m))



