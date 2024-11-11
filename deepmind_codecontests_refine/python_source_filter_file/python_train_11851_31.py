n=int(input())
if n==3:
    print("2 5 63")
elif n==6:
    print("3 4 6 8 9 10")
elif n==7:
    print("2 3 4 6 8 10 15")
else:
    res=[]
    count = 0
    for i in range(1,50000):
        if i % 2 == 0 or i % 3 == 0:
            res.append(i)
            count += 1
        if count == n-1:
            break

    s=sum(res)
    t=res[-1]
    f1 = s%2
    f2 = s%3
    if f1==0 and f2 == 0:
        flag = 0
    elif f1==0 and f2==1:
        flag = 2
    elif f1==0 and f2==2:
        flag = 4
    if f1==1 and f2 == 0:
        flag = 3
    elif f1==1 and f2==1:
        flag = 5
    elif f1==1 and f2==2:
        flag = 1

    if flag == 5 or flag ==1:
        res.pop(1)
        f=0
        for i in range(t+1,t+10):
            if i % 2==0:
                res.append(i)
                f+=1
            if f==2:
                break

    else:
        for i in range(t+1,t+10):
            if i % 6 == flag:
                res.append(i)
                break

    print(" ".join(map(str, res)))