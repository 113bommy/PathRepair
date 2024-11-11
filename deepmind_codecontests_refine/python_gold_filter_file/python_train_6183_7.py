l, d, v, g, r  = [float(x) for x in input().strip().split()]
ttime = l/v
time1 = d/v
time1%=(g+r)
if time1 < g:
    print(ttime)
else:
    print(ttime + (g+r)-time1)

