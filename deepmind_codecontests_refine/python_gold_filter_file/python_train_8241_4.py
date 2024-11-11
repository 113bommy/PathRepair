
for _ in range(int(input())):
    n,m = map(int,input().split())
    sm = 0
    lg = m*10 if n>=(m*10) else n+1
    #print(lg)
    for i in range(m,lg,m):
        sm+=int(str(i)[-1])

    if n>=(m*10):
        bcha = n%(lg)
        sm *=(n//lg)
        #print(sm)
        for i in range(m,bcha+1,m):
            sm+=int(str(i)[-1])
            #print(sm)

    print(sm)
