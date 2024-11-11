h, w = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
c = []
for i in range(n):
    c += (n+1)*a[n]
ans = []
for h_ in range(h):
    a = c[h*w: w+h*w]
    if h % 2 == 0:
        ans.append(a)
    else:
        ans.append(a[::-1])
for i in ans:
    print(*i)