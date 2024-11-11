t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    s = input()
    a = [0] * n
    b = [0] * 27
    p = list(map(int, input().split()))
    d = [0] * n
    for i in p:
        d[i - 1] += 1
    a[n - 1] = d[n - 1]
    for i in range(n - 2, -1, -1):
        a[i] = a[i + 1] + d[i]
    for i in range(n):
        b[ord(s[i]) - ord('a')] += a[i]
    for i in range(n):
        b[ord(s[i]) - ord('a')] += 1
    print(*b)
