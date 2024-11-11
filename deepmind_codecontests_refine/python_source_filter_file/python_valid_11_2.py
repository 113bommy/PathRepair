for _ in range (int(input())) :
    n =  int(input())
    a = []
    for i in range (n) :
        s = list(input())
        a.append(s)
    ans = -999999999
    for i in range (5) :
        ch = chr (97+i)
        b = []
        for i in range (n) :
            t = 0
            t1 = 0
            for j in range (len(a[i])) :
                if (a[i][j] == ch) :
                    t += 1
                else :
                    t1 += 1
            b.append([t-t1,t,t1,i])
        b.sort(reverse = True)
        c = []
        t = 0
        t1 = 0
        for i in range (len(b)) :
            t += b[i][1]
            t1 += b[i][2]
            if (t<t1) :
                break
            c.append(b[i][3])
        if (len(c) > ans) :
            ans = len(c)
    if (ans == -999999999) :
        ans = 0
 
    print(ans)
