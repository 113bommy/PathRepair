q = int(input())
for z in range(q):
    n,x,a,b = list(map(int, input().split()))
    l = min(a, b)
    r = max(a, b)
    while x > 0 and l > 1:
        l -= 1
        x -= 1
    while x > 0 and r < n:
        r -= 1
        x -= 1
    print(abs(l -r ))
