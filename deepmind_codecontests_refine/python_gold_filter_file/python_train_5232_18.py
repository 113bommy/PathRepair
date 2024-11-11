
class seq():
    def __init__(self, l,  c):
        self.length = l

        self.final_ctr = c

import copy
t = int(input())

for _ in range(t):
    n = int(input())
    d = {}
    c = {}
    prev = {}
    ctr = {}
    li = [int(i) for i in input().split(' ')]
    for i in li:
        ctr[i] = ctr.get(i, 0) + 1
    so = sorted(ctr)
    pp = -1
    for i in so:
        prev[i] = pp
        pp = i
    mx = 1
    for i in li:
        if i in d:
            if prev[i] in d and d[prev[i]].final_ctr == ctr[prev[i]]:
                if d[prev[i]].length > d[i].length:
                    d[i].length = d[prev[i]].length
                    d[i].final_ctr = 0
            if c.get(prev[i],0) > d[i].length:
                d[i].length = c[prev[i]]
                d[i].final_ctr = 0
            d[i].final_ctr += 1
            d[i].length += 1
            
        else:
            if prev[i] in d:
                if d[prev[i]].final_ctr == ctr[prev[i]]:
                    d[i] = seq(d[prev[i]].length+1, 1)

                    if c.get(prev[i],0) > d[i].length:
                        d[i].length = c[prev[i]] + 1
                        d[i].final_ctr = 1
                else:
                    d[i] = seq(c[prev[i]]+1, 1)
            else:
                d[i] = seq(1, 1)
        mx = max(mx, d[i].length)
        c[i] = c.get(i, 0) + 1
    print(n-mx)
