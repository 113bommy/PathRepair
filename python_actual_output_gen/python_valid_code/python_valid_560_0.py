t = int(input())
for i in range(t) :
    s,n = list(map(int,input().split()))
    res = []
    if n == 1 :
        print(s)
        continue
    i = 10**len(str(s))
    while len(res) < n-1 :
        while len(res) < n-1 and n-len(res)-1 < s-i :
            res.append(i)
            s-=i
        i//=10
    res.append(s)
    print(*res)