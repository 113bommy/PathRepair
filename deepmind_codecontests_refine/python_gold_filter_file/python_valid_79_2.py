for _ in range(int(input())):
    n=int(input())
    l=[int(i) for i in input()]
    found=False
    for i in range(len(l)):
        if l[i]%2==0 and l[i]!=2:
            print(1)
            print(l[i])
            found=True
            break
        elif l[i]==1:
            print(1)
            print(1)
            found=True
            break
    if found:
        continue
    ll=[3]
    for i in range(len(l)):
        for k in ll:
            if l[i]%k==0 and l[i]!=k:
                    print(1)
                    print(l[i])
                    found=True
                    break
        if found:
                break
    if found:
        continue
    ll=[2,3,5,7]
    for i in range(len(l)):
        for j in range(i+1,len(l)):
            for k in ll:
                if int(str(l[i])+str(l[j]))%k==0:
                    print(2)
                    print(int(str(l[i])+str(l[j])))
                    found=True
                    break
            if found:
                break
        if found:
            break




