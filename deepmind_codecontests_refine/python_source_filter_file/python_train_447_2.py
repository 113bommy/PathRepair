a=int(input())



if a==1:
    print(0)

else:
    t=[]

    for x in range(a):
        t.append(list(map(int,input().split())))
    s=[]

    print(t)

    for k in range(a):
        u=[]
        for j in range(a):
            u.append(t[j][k])

        s.append(sum(u))


    l=0
  


    for jd in range(a):
        for h in range(a):
            if sum(t[jd])<s[h]:
                l+=1

    print(l)

