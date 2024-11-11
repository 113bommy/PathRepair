t = int(input())
for i in range(t):
    n = int(input())
    a = [int(j) for j in input().split()[:n]]
    b = [int(k) for k in input().split()[:n]]
    d = {}
    f=0
    if(a[0]!=b[0]):
        print('NO')
    else:
        for l in range(n):
            if (a[l] not in d):
                d[a[l]] = l
                if (len(d) == 3):
                    break
        for v in range(1,n):
            if(b[v]>0 and a[v]!=b[v]):
                if(1 in d):
                    x1 = d.get(1)
                    if (x1 < v):
                        pass
                    else:
                        f = 1
                        break
                else:
                    f=1
                    break
            elif(b[v]<0 and a[v]!=b[v]):
                if(-1 in d):
                    x2 = d.get(-1)
                    if (x2 < v):
                        pass
                    else:
                        f = 1
                        break
                else:
                    f=1
                    break
            elif(b[v]==0 and a[v]!=b[v]):
                if(a[v]>0):
                    if (1 in d):
                        x3 = d.get(1)
                        if (x3 < v):
                            pass
                        else:
                            f = 1
                            break
                    else:
                        f = 1
                        break
                elif(a[v]<0):
                    if (-1 in d):
                        x4 = d.get(-1)
                        if (x4 < v):
                            pass
                        else:
                            f = 1
                            break
                    else:
                        f = 1
                        break
        if(f==0):
            print('YES')
        else:
            print('NO')
