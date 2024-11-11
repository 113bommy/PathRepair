# e.g. corners = [(2.0, 1.0), (4.0, 5.0), (7.0, 8.0)]
def Area(corners):
    n = len(corners) # of corners
    area = 0.0
    for i in range(n):
        j = (i + 1) % n
        area += corners[i][0] * corners[j][1]
        area -= corners[j][0] * corners[i][1]
    area = abs(area) / 2
    return area*2

for _ in range(int(input())):
    w,d=map(int,input().split())
    x1=list(map(int,input().split()))[1:]
    x2=list(map(int,input().split()))[1:]
    y1=list(map(int,input().split()))[1:]
    y2=list(map(int,input().split()))[1:]
    if 0 in x1:
        x1.remove(0)
    if w in x1:
        x1.remove(w)
    if 0 in x2:
        x2.remove(0)
    if w in x2:
        x2.remove(w)
    if 0 in y1:
        y1.remove(0)
    if d in y1:
        y1.remove(d)
    if 0 in y2:
        y2.remove(0)
    if d in y2:
        y2.remove(d)
    xl1=[]
    xl2=[]
    yl1=[]
    yl2=[]
    for i in x1:
        xl1.append((i,0))
        
    for j in x2:
        xl2.append((j,d))

    for k in y1:
        yl1.append((0,k))

    for l in y1:
        yl2.append((w,l))

        
    n=[max(xl1),max(xl2),max(yl1),max(yl2),min(xl1),min(xl2),min(yl1),min(yl2)]
    m=[(max(xl1),min(xl1)),(max(xl2),min(xl2)),(max(yl1),min(yl1)),(max(yl2),min(yl2))]

    ans=0
    for h in m:
        h1=h[0]
        h2=h[1]
        for p in n:
            ar=Area([h1,h2,p])
            if ar>ans:
                ans=ar
    print(int(ans))
