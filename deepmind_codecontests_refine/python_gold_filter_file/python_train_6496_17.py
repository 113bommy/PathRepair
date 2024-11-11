n, m = map(int, input().split())
l = list(map(int, input().split()))
l.insert(0, 1)
ans = 0
for i in range(m):
    if l[i+1] < l[i]:
        ans += n-l[i]+l[i+1]
    else:
        ans += l[i+1]-l[i]
print(ans)