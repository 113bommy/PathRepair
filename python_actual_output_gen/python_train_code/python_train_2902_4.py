for n in range(int(input())):
    x=int(input())
    s=sorted(list(map(int,input().split())))
    if sum(s)!=0 and 0 not in s:
        print(0)
        continue

    res=0
    sm=0
    for n in range(x):
        if s[n]==0:
            res+=1
            s[n]=1

    if sum(s)<=0:
        res+=1-sum(s)

    print(res)
        