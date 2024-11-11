for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    dl=[]
    for i in range(len(a)):
        if a[i] not in dl:
            dl.append(a[i])
    for j in range(len(dl)):
        print(dl[j],end=' ')