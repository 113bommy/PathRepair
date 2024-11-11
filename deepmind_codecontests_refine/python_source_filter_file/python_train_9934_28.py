h1,m1=list(map(int,input().split(":")))
h2,m2=list(map(int,input().split(":")))
if m1<m2:
    m1=m1+1
    h1=h1-1
    t=m1-m2
    if h1<h2:
        h1=h1+24
        p=h1-h2
        if t<10:
            t="0"+str(t)
        if p<10:
            p="0"+str(p)
        print("{}:{}".format(p,t))
    else:
        p=h1-h2
        if t<10:
            t="0"+str(t)
        if p<10:
            p="0"+str(p)
        print("{}:{}".format(p,t))
else:
    t=m1-m2
    if h1<h2:
        h1=h1+24
        p=h1-h2
        if t<10:
            t="0"+str(t)
        if p<10:
            p="0"+str(p)
        print("{}:{}".format(p,t))
    else:
        p=h1-h2
        if t<10:
            t="0"+str(t)
        if p<10:
            p="0"+str(p)
        print("{}:{}".format(p,t))
