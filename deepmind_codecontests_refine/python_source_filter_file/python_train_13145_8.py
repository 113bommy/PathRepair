cases = int(input())
for t in range(cases):
    x,y = list(map(int,input().split()))
    c = list(map(int,input().split()))
    east = min(c[1],c[0]+c[2])
    west = min(c[4],c[3]+c[5])
    neast = min(c[0],c[1]+c[5])
    nwest = min(c[5],c[0]+c[4])
    seast = min(c[2],c[1]+c[3])
    swest = min(c[3],c[2]+c[4])
    # east = min(east,neast+seast)
    # west = min(west,nwest+swest)
    # nwest = min(nwest,neast+west)
    # seast = min(seast,east+swest)
    out1 = 0
    ###app1
    if x>=0:
        out1 += abs(x)*nwest
    else:
        out1 += abs(x)*seast
    if y>=0:
        out1 += abs(y)*east
    else:
        out1 += abs(y)*west

    out2 = 0
    ###app2
    if x>=0:
        out2 += abs(x)*neast
    else:
        out2 += abs(x)*swest
    if y>=0:
        out2 += abs(y-x)*east
    else:
        out2 += abs(y-x)*west

    out3 = 0
    ###app2
    if y >= 0:
        out3 += abs(y) * neast
    else:
        out3 += abs(y) * swest
    if y >= x:
        out3 += abs(y-x) * seast
    else:
        out3 += abs(y-x) * nwest
    print(min(out1,out2,out3))