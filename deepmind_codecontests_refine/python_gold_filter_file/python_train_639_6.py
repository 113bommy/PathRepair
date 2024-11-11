n, m, k = map(int, input().split())
lst = list(map(int, input().split()))
ans = 0
page = k
eaten = 0
i = 0
while i < m:
    elem = lst[i]
    if page < elem:
        if eaten:
            page += eaten
            eaten = 0
            ans += 1
        else:
            page += (elem - page + k - 1) // k * k
    else:
        eaten += 1
        i += 1
print(ans + 1)