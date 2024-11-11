n,m=map(int,input().split())
l1=set()
l2=set()
for i in range(m):
    k,t=sorted(map(int,input().split()))
    l1.add(k)
    l2.add(t)
if m == 0:
    print(n-1)
else:
    l3=set()
    for i in l1:
        l3.add(i)
    for i in l2:
        l3.add(i)
    if len(l3) != len(l1)+len(l2):
        print(0)
    else:
        maxl=max(l1)
        minh=min(l2)
        if maxl > minh:
            print(0)
        else:
            if len(l3) == n:
                if len(l1) != 0 and len(l2) != 0:
                    print(1)
                else:
                    print(0)
            else:
                if maxl > minh:
                    print(0)
                else:
                    t=0
                    for i in range(1,n+1):
                        if i not in l3:
                            if i < maxl:
                                pass
                            elif i > minh:
                                pass
                            else:
                                t+=1
                    print(t+1)
