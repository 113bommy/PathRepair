rot = ((1,2,4,3),(2,0,3,5),(0,1,5,4))
f = input().split()

for i in range(int(input())):
    t, s = map(f.index, input().split())
    for j in rot:
        if (t in j)*(s in j):
            continue
        d = rot.index(j)
        if (j.index(t) - j.index(s)) %4 == 1:
            d -= 5
    print(f[abs(d)])