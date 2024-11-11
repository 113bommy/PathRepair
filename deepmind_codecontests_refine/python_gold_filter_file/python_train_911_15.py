n = int(input())
p = list(map(int, input().split()))
d = [min(i, n - i - 1, j, n - j - 1) for i in range(n) for j in range(n)]
ans = 0
l = [1] * (n ** 2)
for i in p:
    ans += d[i - 1]
    l[i - 1] = 0
    que = [i - 1]
    while que:
        s = que.pop()
        if not s % n == n - 1:
            if d[s + 1] > d[s] + l[s]:
                que.append(s + 1)
                d[s + 1] = d[s] + l[s]
        if s % n:
            if d[s - 1] > d[s] + l[s]:
                que.append(s - 1)
                d[s - 1] = d[s] + l[s]
        if s >= n:
            if d[s - n] > d[s] + l[s]:
                que.append(s - n)
                d[s - n] = d[s] + l[s]
        if n ** 2 > s + n:
            if d[s + n] > d[s] + l[s]:
                que.append(s + n)
                d[s + n] = d[s] + l[s]
print(ans)
