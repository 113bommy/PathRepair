t = int(input())
for _ in range(t):
    n = int(input())
    li = list(map(int,input().split()))
    l =[]
    for i in range(n):
        if li[i] == 1:
            l.append(i)
    c =0 
    if len(l)==1:
        print(0)
    else:
        print(*l)
        for i in range(len(l)-1):
            c+=abs(l[i+1]-l[i]-1)
        print(c)