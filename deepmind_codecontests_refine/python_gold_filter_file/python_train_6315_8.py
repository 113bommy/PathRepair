import heapq
n,m = [int(s) for s in input().split()]
q0,q1 = [],[]
ans = [0]*n
for i in range(m):
    si, di, ci = [int(s) for s in input().split()]
    si -= 1
    di -= 1
    ans[di] = m+1
    heapq.heappush(q0, (si, di, ci, i))

for currday in range(n):
    while len(q0) and q0[0][0] <= currday:
        si,di,ci,i = heapq.heappop(q0)
        heapq.heappush(q1, (di,si,ci,i))
    if len(q1) and ans[currday] == 0:
        if currday > q1[0][0]:
            break
        ans[currday] = q1[0][3]+1
        if q1[0][2] == 1:
            heapq.heappop(q1)
        else:
            q1[0] = (q1[0][0], q1[0][1], q1[0][2]-1, q1[0][3])

if len(q1) == 0 and len(q0) == 0:
    print(*ans)
else:
    print(-1)