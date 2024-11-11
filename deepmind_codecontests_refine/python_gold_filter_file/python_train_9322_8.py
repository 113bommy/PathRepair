nc = int(input())

cf = input().split()

for i in range(len(cf)):
    cf[i] = int(cf[i])

# print(cf)

cf.sort()

# print(cf)

nq = int(input())

def b_sch(q, vals):
    # trying to find the first value thats greater than q
    # print(q)
    # print(vals)
    if vals[-1] <= q:
        return len(vals)
    if vals[0] > q:
        return 0
    lo = 0
    hi = len(vals) - 1
    md = int((lo + hi)/2)
    while lo + 1 < hi:
        md = int((lo + hi)/2)
        if vals[md] <= q:
            lo = md
        elif vals[md] > q:
            hi = md
    # ret = md if vals[md] <= q else md - 1 
    
    return hi

for x in range(nq):
    print(b_sch(int(input()), cf))