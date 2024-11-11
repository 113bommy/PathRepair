from math import sqrt
n, p = map(int, input().split())
a = []

if n == 1:
    print(p)
    exit()

for i in range(2, int(sqrt(p+1))+1):
    tmp = 0
    while p % i == 0:
        p //= i
        tmp += 1
    if tmp >= n:
        tmp //= n
        a.append(i*tmp)

ans = 1
for i in a:
    ans *= i

print(ans)
