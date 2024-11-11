a = [input(),input(),input()]
l = [len(a[0]),len(a[1]),len(a[2])]
ans = l[0]+l[1]+l[2]

def check(a0, l0, a1, l1, delta):
    # stt1 >= stt0, stt1 - stt0 >=l0 must return True
    i = delta
    j = 0
    while (i<l0) and (j<l1):
        if a0[i] != a1[j]:
            if a0[i] != '?' and a1[j] != '?':
                return False
        i += 1
        j += 1
    return True

memoLen = ans-min(l[0],l[1],l[2])+1
memo = [[[1]*memoLen for i in range(3)] for j in range(3)]
comb2 = [(0,1),(1,0),(1,2),(2,1),(0,2),(2,0)]
for x, y in comb2:
    me = memo[x][y]
    a0, a1 = a[x],a[y]
    l0, l1 = l[x],l[y]
    for delta in range(0,l0):
        if not check(a0,l0, a1,l1, delta):
            me[delta] = 0

comb = [(0,1,2),(0,2,1),(1,0,2),(1,2,0),(2,1,0),(2,0,1)]
for i,j,k in comb:
    l0, l1, l2 = l[i],l[j],l[k]
    for stt1 in range(0,l0+1):
        if memo[i][j][stt1]:
            l01 = max(l0,stt1+l1)
            for stt2 in range(stt1,l01+1):
                if memo[j][k][stt2-stt1] and memo[i][k][stt2]:
                    l012 = max(l01,stt2+l2)
                    ans = min(ans,l012)
print(ans)