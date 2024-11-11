t = int(input())
for _ in range(t):
    n,x = [int(i) for i in input().split()]
    s = []
    for _ in range(n):
        s.append([int(i) for i in input().split()])
    g = 0
    j = 0
    c = 0
    for d,h in s:
        if d-h>g:
            g = d-h
        if d>j:
            j = d
    f = x-j
    if f==0:
        print(1)
    else:
        c+=1
        if g==0:
            print(-1)
        else:
            print((f+g-1)//g+c)
