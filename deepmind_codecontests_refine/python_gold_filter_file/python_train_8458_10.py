t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    l=[]
    for i in a:
        if i not in l:
            l.append(i)
    print(*l)