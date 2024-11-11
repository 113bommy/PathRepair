def isInt(n):
    return int(n) == float(n)
    
a = list(map(int, input().split()))
arifm = []
geom = []
da = a[1] - a[0]
dg = a[1] / a[0]
for i in range(1, len(a)):
    arifm.append(a[i] - a[i - 1])
    geom.append(a[i] / a[i - 1])
arifm = set(arifm)
geom = set(geom)
if len(arifm) > 1 and len(geom) > 1:
    print(42)
elif len(arifm) == 1:
    print(a[len(a) - 1] + da)
elif len(geom) == 1 and isInt(a[len(a) - 1] * dg) == 1:
    print(int(a[len(a) - 1] * dg))
else:
    print(42)