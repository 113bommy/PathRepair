t = int(input())
for i in range(t):
    A =  list(map(int,input().split()))
    n = A[0]
    m = A[1]
    rb = A[2]
    cb = A[3]
    rd = A[4]
    cd = A[5]
    l = []
    if rb <= rd :
        l.append(rd-rb)
    else :
        l.append(2*n - rb- rd)
    if cb <= cd:
        l.append(cd - cb)
    else :
        l.append(2*n - cb - cd)
    m = float("inf")
    for i in l:
        if m > i :
            m = i
    print(m)
