#besme taala
#ya_hossein
import sys
input=lambda:sys.stdin.readline().rstrip()
n, b = map(int, input().split())
ans = 1e21
for i in range(2, 1000000):
    if b % i == 0:
        s, c = 0, 0
        while b % i == 0:
            s += 1
            b /= i
        z = i
        while z <= n:
            c += n//z
            z *= i
        ans = min(ans, c//s)
if b != 1:
    c = 0
    z = b
    while z <= n:
        c += n//z
        z *= b
    ans = min(ans, c)
print(ans)