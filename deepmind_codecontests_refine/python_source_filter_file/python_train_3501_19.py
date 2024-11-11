n,m = map(int,input().split())
S = input()
Line = []
for i in range(n):
    Line.append(S[i])
for i in range(m):
    l,r,c1,c2 = map(str,input().split())
    l = int(l)
    r = int(r)
    if l == r:
        if Line[l-1] == c1:
            Line[l-1] = c2
    else:
        for i in range(l-1,r-1):
            if Line[i] == c1:
                Line[i] = c2
            else:
                pass
for i in range(n):
    print(Line[i],end="")
