n = int(input())
m = (n+2)//2
ans = []
for i in range(1, n+1):
    if i <= m:
        r = 1
        c = i
    else:
        r = m
        c = m-(n-i)
    ans.append((r, c))
print(m)
for i in range(n):
    print(*ans[i])
