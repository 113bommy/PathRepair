t=int(input())
for _ in range(t):
    # n,k = map(int, input().split())
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    mini = a[0]
    for i in range(n-1):
        val = a[i+1]-a[i]
        if(val<mini):
            mini=val
    print(mini)