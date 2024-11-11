n = int(input())
a = {}
a['POLYCARP'] = 1
m = 1
for i in range(n):
    k1,do,k2 = [i.upper() for i in input().split()]
    r = a[k2]+1
    a[k1] = r
    if r>m:
        m=r
print(r)
