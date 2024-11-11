n, k = map(int, input().split())
d = list(input().split())
ans = 100000
for i in range(n, 10001):
    for j in range(k):
        if d[j] in str(i):
            break
    else:
        if ans > i:
            ans = i
print(ans)
