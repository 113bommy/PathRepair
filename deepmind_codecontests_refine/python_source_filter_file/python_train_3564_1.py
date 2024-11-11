for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    pl=ne=-1
    c=1
    for i in range(n):
        if a[i]==1:
            pl=i
            break
    for i in range(n):
        if a[i]==-1:
            ne=i
            break
    for i in range(n):
        if b[i]>a[i] and pl>=i:
            c=0
            break
        elif b[i]<a[i] and ne>=i:
            c=0
            break
    if c:
        print("YES")
    else:
        print("NO")                    
