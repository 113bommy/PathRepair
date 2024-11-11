n, k = list(map(int, input().split()))
ar = list(map(lambda x:int(x)-1, input().split()))

fidx = [n]*n
lidx = [-1]*n
for i, e in enumerate(ar):
    lidx[e] = i
    fidx[e] = min(fidx[e], i)

out = 0
for v in range(n):
    if fidx[v] == n:
        out += 3 if v not in (0, n-1) else 2
    else:
        if v != 0 and lidx[v-1] < fidx[v]:
            out += 1
        if v != n-1 and lidx[v+1] < fidx[v]:
            out += 1
    
print(out)
