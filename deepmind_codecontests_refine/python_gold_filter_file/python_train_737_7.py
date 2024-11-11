for _ in range(1):
    n=int(input())
    l=list(map(int,input().split()))
    c=-1
    for i in range(n):
        if l[i]>c+1:
            print(i+1)
            break
        c=max(c,l[i])
        
    else:
        print(-1)
            