def solve():
    n = int(input())
    a = list(map(int, input().split()))
    z = []
    z.extend(a)
    a.sort()
    s = ""
    for i in range(n-1,-1,-1):
        for j in range(0,i):
            if a[j:i].__contains__(a[i]-a[j]):
                # print(a[i],a[j],a[i]-a[j])
                x = z.index(a[i])+1
                s = s + str(x)+" "
                # print("h")
                z[z.index(a[i])] = -100
                y = z.index(a[j])+1
                # print("b")
                s = s + str(y)+" "
                z[z.index(a[j])] = -100
                t = z.index(a[i]-a[j])+1
                s = s + str(t)
                print(s)
                return
    print(-1)
    return
try:
    solve()
except:
    pass