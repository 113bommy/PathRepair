t = int(input())
while t:
    t-=1
    m = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    p1 = [0]
    p2 = [0]

    for i in range(m):
        p1.append(p1[-1] + a[i])
        p2.append(p2[-1] + b[i])
    
    ans = float("inf")
    for i in range(m):
        ans = min(ans, max(p1[-1] - p2[i + 1], p2[i]))
    print(ans)