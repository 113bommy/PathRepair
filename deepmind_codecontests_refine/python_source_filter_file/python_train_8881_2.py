for idfghjk in range(int(input())):
    n=(int(input()))
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    ai=[]
    aj=[]
    for i in range(n):
        if a[i]>b[i]:
            for j in range(a[i]-b[i]):
                ai.append(i)
        if a[i]<b[i]:
            for j in range(b[i]-a[i]):
                aj.append(i)
    if len(ai)==len(aj):
        print(len(ai))
        for i in range(len(ai)):
            print(ai[i],aj[i])
    else:
        print(-1)