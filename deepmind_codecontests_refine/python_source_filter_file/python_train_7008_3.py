from sys import stdin, stdout
ip = lambda : stdin.readline().rstrip("\r\n")
ips = lambda : ip().split()
out = lambda x, end='\n': stdout.write(str(x)+end)
mod = 1e9+7
from math import gcd

for _ in range(int(ip())):
    n = int(ip())
    ans = 0
    lcm = 1
    r = n
    for i in range(2, n+2):
        lcm = lcm//gcd(lcm, i)*i
        ans += ((r-n//lcm)*i)%mod
        r = n//lcm
        if r<=0:
            break
    out(int(ans%mod))