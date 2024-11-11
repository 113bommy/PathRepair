for _ in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    m = max(l)
    num = []
    for i in range(n):
        l[i] = m-l[i]
    m = max(l)
    for i in range(n):
        num.append(m-l[i])
    if k%2==0:
        print(*l)
    else:print(*num)