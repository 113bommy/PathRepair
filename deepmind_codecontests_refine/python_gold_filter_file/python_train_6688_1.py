ans = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if k not in a:
    	ans.append('no')
    	continue
    if n == 1:
        ans.append('yes' if a[0] == k else 'no')
        continue
    good = False
    for i in range(n - 1):
        if a[i] >= k and a[i + 1] >= k:
            good = True
    for i in range(1, n):
        if a[i] >= k and a[i - 1] >= k:
            good = True
    for i in range(1, n - 1):
        if a[i - 1] >= k and a[i + 1] >= k:
            good = True
    ans.append('yes' if good else 'no')
print('\n'.join(ans))