from sys import stdin
t = int(stdin.readline())
for _ in range(t):
    n, k = map(int,stdin.readline().split())
    a = list(map(int,stdin.readline().split()))
    m = -(10 ** 10)
    for i in range(max(0, n-150), n):
        for j in range(i+1, n):
            m = max(m, (i+1) * (j+1) - k * (a[i] | a[j]))
    print(m)