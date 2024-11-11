import sys


def get_one(n):
    cnt = 0
    while n > 0:
        if n % 2 == 1:
            cnt += 1
        n //= 2
    return cnt


n, p = map(int, input().split())
for i in range(20):
    if n > i * p and get_one(n - i * p) <= i <= n - i * p:
        print(i)
        sys.exit()
print(-1)
