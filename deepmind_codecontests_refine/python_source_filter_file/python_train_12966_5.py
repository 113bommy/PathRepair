n,m = map(int,input().split())
strok = [0] * (n+1)
stolb = [0] * (n+1)
stol = 0
stro = 0
otvat = [str(n**2)]
for i in range(1,m+1):
    k = 0
    l = list(map(int,input().split()))
    if strok[l[0]] == 0:
        strok[l[0]] = 1
        k += n - stro
        stro += 1
    if stolb[l[1]] == 0:
        stolb[l[1]] = 1
        k += n - stol - 1
        stol += 1
    otvat.append(str(int(otvat[i-1]) - k))
print(' '.join(otvat[1:]))

