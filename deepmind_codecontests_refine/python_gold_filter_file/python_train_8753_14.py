n, k, s = map(int, input().split())
if k > s or k * (n - 1) < s:
    print ('NO')
    exit()
ans = []
cur = 1
for i in range(1, k + 1):
    if k - i <= s - n + 1:
        if cur == 1:
            ans.append(n)
            cur = n
        else:
            ans.append(1)
            cur = 1
        s -= (n - 1)
    else:
        if i == k:
            if cur == 1 or cur == 2: ans.append(cur + s)
            else: ans.append(cur - s)
        else:
            if cur == 1: ans.append(2); cur = 2;
            elif cur == 2: ans.append(1); cur = 1;
            elif cur == n: ans.append(n - 1); cur = n - 1;
            elif cur == n - 1: ans.append(n); cur = n;
        s -= 1
print('YES')
print (' '.join(map(str, ans)))
