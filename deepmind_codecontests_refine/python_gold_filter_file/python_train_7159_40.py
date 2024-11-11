N,Q = map(int,input().split())
BIT = [0]*(N+1)

def BIT_query(idx):
    res_sum = 0
    while idx > 0:
        res_sum += BIT[idx]
        idx -= idx&(-idx)
    return res_sum

def BIT_update(idx,x):
    while idx <= N:
        BIT[idx] += x
        idx += idx&(-idx)
    return

c = [-1]+list(map(int,input().split()))
lastAppeared = [-1]*(N+1)
ans = [0]*Q
queries = []
for q in range(Q):
    l,r = map(int,input().split())
    queries.append(r*10**12+l*10**6+q)
queries.sort()

curR = 0
for i in range(Q):
    query = queries[i]
    r = query//10**12
    query %= 10**12
    l = query//10**6
    q = query % 10**6
    while curR < r:
        curR += 1
        new = c[curR]
        last = lastAppeared[new]
        if last != -1:
            BIT_update(last,-1)
        lastAppeared[new] = curR
        BIT_update(curR,1)
    ans[q] = BIT_query(r)-BIT_query(l-1)
for i in range(Q):
    print(ans[i])