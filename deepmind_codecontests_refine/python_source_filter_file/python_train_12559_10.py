import collections

t = int(input())
for i in range(t):
    n = int(input())
    l = []
    r = []
    for i in range(n):
        (ll, rr) = map(int, input().split())
        l.append(ll)
        r.append(rr)
    q = collections.deque()
    
    cur_t = 1
    cur_student = 0
    while cur_student < n or len(q):
        while cur_student < n and l[cur_student] == cur_t:
            q.append(cur_student)
            cur_student += 1
        while len(q):
            i = q.popleft()
            if cur_t >= r[i]:
                print(0, end = ' ')
                continue
            print(cur_t, end = ' ')
            break
        cur_t += 1
    print()