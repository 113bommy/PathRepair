t = int(input())
for j in range(t):
    n,x = input().split()
    n = int(n)
    x = int(x)
    lst = [int(i) for i in input().split()]
    Sum=sum(lst)
    mc=10^9 +7
    index=0
    for i in range(n):
        c1=0
        a = lst[i]
        if i==0 or a%x**mc!=0:
            while a%x == 0:
                c1 = c1 + 1
                a = a/x
            if c1<mc:
                mc = c1
                index = i
        if mc==0:
            break
    ans = Sum*(mc+1)
    for i in range(n):
        if i!=index:
            ans = ans + lst[i]
        else:
            break
    print(ans)