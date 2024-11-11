for _ in range(int(input())):
    n=int(input())
    a=[[-1]*n for z in range(n)]
    for z in range(n):
        a[z]=list(input())
    ansl=[]
    if a[0][1]==a[1][0]:
        v=a[0][1]
        if a[-1][-2]==v:
            ansl.append([n,n-1])
        if a[-2][-1]==v:
            ansl.append([n-1,n])
    else:
        if a[-1][-2]==a[-2][-1]:
            v=a[-1][-2]
            if a[0][1]==v:
                ansl.append([1,2])
            if a[1][0]==v:
                ansl.append([2,1])
        else:
            v=a[0][1]
            ansl=[[1,0]]
            if a[-1][-2]==v:
                ansl.append([n,n-1])
            if a[-2][-1]==v:
                ansl.append([n-1,n])
    print(len(ansl))
    for z in ansl:
        print(*z)
