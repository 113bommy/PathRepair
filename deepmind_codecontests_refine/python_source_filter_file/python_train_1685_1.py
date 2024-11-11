t=int(input())
for i in range(0,t):
    n = int(input())
    l=0
    a=(list(map(int, input().split())))
    c=999999999
    for j in range(n-1,-1,-1):
        if c>a[j]:
            c=a[j]
        else:
            l+=1
    print(l)