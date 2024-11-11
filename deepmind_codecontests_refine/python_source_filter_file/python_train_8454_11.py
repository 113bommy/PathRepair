for _ in range(int(input())):
    n=int(input())
    lis=list(map(int,input().split()))
    replc=0
    add=0
    step=0
    for i in range(n):
        if lis[i]==0:
            lis[i]=1
            step+=1
        add+=lis[i]
    if add==0:
        print(step)
    else:
        print(step+1)
