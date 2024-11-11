n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print('YES')
    print(a[0])
    exit()

cnt = [0] * 1001
for _ in a: cnt[_] += 1

odd, x = 0, -1
for i, _ in enumerate(cnt): 
    if _ % 2: 
        odd += 1
        x = i 

if odd > 1 or n % 2 == 0 and odd:
    print('NO')
    exit()

ans = [[0]*n for _ in range(n)]
if n % 2: 
    ans[n//2][n//2] = x
    cnt[x] -= 1

for i in range(n//2):
    for j in range(n//2):
        for v, _ in enumerate(cnt):
            if _ >= 4:
                ans[i][j] = ans[n-1-i][j] = ans[i][n-1-j] = ans[n-1-i][n-1-j] = v
                cnt[v] -= 4
                break

if n % 2:
    for i in range(n//2):
        for v, _ in enumerate(cnt):
            if _ >= 2:
                ans[i][n//2] = ans[n-1-i][n//2] = v
                cnt[v] -= 2
                break

    for j in range(n//2):
        for v, _ in enumerate(cnt):
            if _ >= 2:
                ans[n//2][j] = ans[n//2][n-1-j] = v
                cnt[v] -= 2
                break

y = 0
for i in range(n):
    for j in range(n):
        if ans[i][j] == 0: y += 1

if y:
    print("NO")
else:
    print("YES")
    for i in range(n):
        for j in range(n):
            print(ans[i][j], end=' ')
        print()
