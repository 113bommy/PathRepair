x = int(input())
g = []
for i in range (x):
    r = 1
    s = 0
    l = int(input())
    while r:
        if l >=0.1:
            s = s + l
            l = l/10
        elif s - int(s) > 0:
            g.append(int(s))
            r = 0
        else:
            g.append(int(s))
            r = 0
i=0
for i in range(len(g)):
    print(g[i])
    i +=1
