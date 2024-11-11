t = int(input())
for i in range(t):
    n, k, d = map(int, input().split())
    lst = list(map(int, input().split()))
    set1 = set()
    for i in range(d):
        set1.add(lst[i])
    ans = len(set1)
    for i in range(d, n):
        set1 = set(lst[i - d + 1:i + 1])
        ans = min(ans, len(set1))
    print(ans)     