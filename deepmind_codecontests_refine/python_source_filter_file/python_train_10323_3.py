n = int(input())
u = [int(i) for i in input().split()]
d, s = dict(), dict()
m = 0
for i, v in enumerate(u):
    t = d.get(v, 0)
    d[v] = t + 1
    s[t + 1] = s.get(t + 1, 0) + 1
    if t > 0:
        if s.get(t, 0) > 1:
            s[t] -= 1
        else:
            del s[t]
    # print(d)
    # print(s)
    if (len(s) == 1 and (1 in s.keys()) or 1 in s.values()) or \
            (len(s) == 2 and (s.get(1, 0) == 1 or
                              (max(s.keys()) == min(s.keys()) + 1 and s[max(s.keys())] == 1))):
        m = i
        # print(m + 1)
print(m + 1)
