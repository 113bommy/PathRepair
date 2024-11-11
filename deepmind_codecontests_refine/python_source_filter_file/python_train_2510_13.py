from math import sqrt
n = int(input())
m = sqrt(n)
i = 1
cnt = 0
while i <= m:
    if n % i == 0:
        cnt += 2
    i += 1
if m * m == n:
    cnt -= 1

print(cnt)