n, q = map(int, input().split())
l = [0]*n; u = [0]*n; lmin = n-2; umin = n-2; lgoal = n; ugoal = n
for _ in range(q):
    s, t = map(int, input().split())
    if s == 1:
        if t > ugoal: u[t-1] = 0
        else:
            for i in range(t, ugoal-1):u[i] = umin
            lmin = t-2; ugoal = t
    else:
        if t > lgoal: l[t-1] = 0
        else:
            for i in range(t, lgoal-1):l[i] = lmin
            umin = t-2; lgoal = t
print(sum(l)+sum(u)+lmin*umin)