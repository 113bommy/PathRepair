t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    l=[]
    for j in a:
        if j not in l:
            l.append(j)
    print(l)