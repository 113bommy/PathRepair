n, m = map(int, input().split())
a = [0] * (n)
b = [list(map(int, input().split())) + [i] + [0] for i in range(m)]
b.sort(key= lambda x:x[1])
for i, (v, x, y, z) in enumerate(b):
    a[v-1] += 1
    b[i][3] = a[v-1]
b.sort(key = lambda x:x[2])
for v,x,y,z in b:
    print("{0:06d}{0:06d}".format(v,z))