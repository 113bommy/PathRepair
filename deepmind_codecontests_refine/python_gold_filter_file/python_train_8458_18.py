for _ in range(int(input())):	
    n=int(input())
    a=list(map(int,input().split()))
    l=[]
    for i in range(n*2):
        if a[i] not in l:
            l.append(a[i])

    print(*l)
