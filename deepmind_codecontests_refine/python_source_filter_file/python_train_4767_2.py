import sys
input = sys.stdin.buffer.readline

k, q = map(int, (input().split()))
d = list(map(int, (input().split())))

for qi in range(q):
    n, x, m = map(int, input().split())
    last = x
    eq = 0
    for i in range(k):
        num = (n-1-i+k-1)//k
        last += (d[i]%m) * num
        if d[i]%m == 0: eq += num
    ans = (n-1) - (last//m - x//m) - eq
    print(ans)