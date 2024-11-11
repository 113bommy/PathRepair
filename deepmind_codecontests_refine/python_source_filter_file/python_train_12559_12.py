import collections

def solve():
    ans = []
    q = collections.deque()
    n = int(input())
    for i in range(n):
        t1, t2 = map(int, input().split())
        q.append((t1, t2))
    t = max(0, q[0][0])
    while q:
        cur = q.popleft()
        if cur[1] < t:
            #print(0, end = ' ')
            ans.append(0)
            if not q:
                continue
            t = q[0][0]
        else:
            ans.append(t)
            if not q:
                continue
            t = max(t + 1, q[0][0])
            #print(t)
    return ans

t = int(input())
res = []
for i in range(t):
    res.append(solve())
for i in range(t):
    print(*res[i])