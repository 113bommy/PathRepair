t = int(input())
for _ in range(t):
    n,x = list(map(int, input().split()))
    a = list(map(int, input().split()))
    a.sort()
    a.reverse()
    s = 0
    result = 0
    for i in range(n):
        s += a[i]
        if s/(i+1) > x:
            result = i+1
    print(result)