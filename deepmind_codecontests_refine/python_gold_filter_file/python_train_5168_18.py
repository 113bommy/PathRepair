def h(n, a):
    v=min(a)
    minx=n
    w=[]
    for i in range(0,n):
        if a[i]==v:
            w.append(i)
            if len(w)>=2:
                x=w[-1]
                y=w[-2]
                if x-y<minx:
                    minx=x-y
    return minx

n = input().strip()
a = input().strip().split()
a = list(map(int, a))
print(h(int(n), a))