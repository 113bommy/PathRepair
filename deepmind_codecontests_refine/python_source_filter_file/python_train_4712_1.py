t = int(input())
MAX = 99999999
for _ in range(t):
    n,x = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort(reverse=True)
    ans = 0
    current = 0
    cur_min = MAX
    for i in range(n):
        cur_min = min(cur_min,a[i])
        current+=1
        if cur_min * current >= x:
            ans+=1
            cur_min = MAX
            current = 0
    print(ans)
