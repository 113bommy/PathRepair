gcd = lambda a, b: a if b == 0 else gcd(b, a % b)
n = int(input())
a = [0] + list(map(int, input().split()))
t = 1
for i in range(1, n + 1):
    if i == a[i]:
        continue
    x = i
    cnt = 1
    while a[x] != i and cnt <= n:
        x = a[x]
        cnt += 1
    if cnt >= n + 1:
        print(-1)
        exit()
    
    if cnt % 2 == 0:
        cnt//=2
    
    t = t * cnt // gcd(t, cnt)
print(t)
