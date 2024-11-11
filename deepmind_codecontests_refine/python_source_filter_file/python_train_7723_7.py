t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    for i in range(a[0],0,-1):
        c=0
        for j in range(n):
            if a[j] >= i:
                c+=1
        if c >= i:
            print(c)
            break