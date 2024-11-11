from bisect import bisect_left
def fun(ind,alr,ll,sll):
    if ind in alr:
        return alr[ind]
    k = bisect_left(sll,ind)
    md = ll[k]
    return fun((ind-sll[k])%md,alr,ll,sll)
pos = {}
m = int(input())
l = 0
cp = []
cpl = []
for _ in range(0,m):
    q = [int(i) for i in input().split()]
    if q[0] == 1:
        pos[l] = q[1]
        l += 1
    else:
        cp.append(q[1])
        l += q[1]*q[2]
        cpl.append(l)
n = int(input())
qq = [int(i)-1 for i in input().split()]
ans = [fun(i,pos,cp,cpl) for i in qq]
print(*ans)




