def countPairs(n, m):
    cnt = 0
    for a in range (0, 100):
        for b in range(0, 100):
            if (a*a + b == n) and (a + b*b == m):
                cnt = cnt + 1
    return cnt

n, m = map(int, input().split())
print(countPairs(n, m))