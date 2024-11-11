t = int(input())
for i in range(t):
    n = int(input())
    var = list(map(int,input().split()))
    res=0
    for p in range(n-1):
        res = max(res, var[p]*var[p-1])
    print(res)