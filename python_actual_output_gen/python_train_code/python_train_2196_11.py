n = [int(i) for i in input().split()][0]
a = [int(i) for i in input().split()]

t = 0
tend = 102
dv = 10000000

for i in range(-tend,tend):
    d = 0
    for ai in a:
        d += min(min(abs(i-ai),abs(i-1-ai)),abs(i+1-ai))

    if d < dv:
        dv = d
        t = i

print(t,dv)