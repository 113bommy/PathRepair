for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    h=[]
    for i in l:
        if i not in h:
            h.append(i)
    print(*h)