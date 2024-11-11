for _ in range(1):
    n=int(input())
    l=list(map(int,input().split()))
    c=0
    for i in range(n):
        if l[i]>c:
            print(i+1)
            break
        c=max(c,l[i])
        c+=1
    else:
        print(-1)
            