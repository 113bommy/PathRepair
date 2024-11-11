import sys, math, os.path

FILE_INPUT = "b.in"
DEBUG = os.path.isfile(FILE_INPUT)
if DEBUG: 
    sys.stdin = open(FILE_INPUT)    

def ni():
    return map(int, input().split(" "))

def nia(): 
    return list(map(int,input().split()))

def log(x):
    if (DEBUG):
        print(x)

t, = ni()
for _ in range(0,t):
    n, = ni()

    queue = []
    tea = [0] * n
    cur = 0
    for i in range(0,n):
        li,ri = ni()
        queue.append([i,li,ri])
        
        while (cur <= li and len(queue) > 0):
            ii, ll, rr = queue.pop(0)
            if (cur < ll):
                cur = ll
            if (cur < rr):
                tea[ii] = cur
                cur += 1
        # log(queue)
        # log(tea)
    for [ii,ll,rr] in queue:
        if (cur <= rr):
            tea[ii] = cur
            cur += 1
    
    print(" ".join(map(str,tea)))

        
                    
        # r.append(ri)
        # ii.append(i)
