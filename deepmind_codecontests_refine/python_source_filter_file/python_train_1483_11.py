def f():
    n = int(input().split()[0])
    l = [int(x) for x in input().split()]
    s = 0
    for i in l:
        s += i
    if s < n:
        print(-1)
        return
    o = s-n
    b = 0
    u = "1"
    p = 0
    for i in range(0,len(l)-1):
        if l[i]-1<o:
            p = b+2
            b += 1
            o -= l[i]-1
        elif o == 0:
            p = b+l[i]+1
            b += l[i]
        else:
            p = b+l[i]-o+1
            b += l[i]-o
            o = 0
        if b+l[i+1] >= n:
            print(-1)
            return
        u += " "+str(p)
    print(u)
f()
