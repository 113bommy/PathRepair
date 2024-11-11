import math
n, m = map(int, input().split())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
p = p[0]
q = q[0]

if n > m:
    if (p < 0 or q < 0) and (p >= 0 or q >= 0):
        print("-Infinity")
    else:
        print("Infinity")
elif m > n:
    print("0/1")
else:
    for i in range(1, n+1):
        p *= i
    for i in range(1, m+1):
        q *= i
    ans = f"{int(p/math.gcd(p, q))}/{int(q/math.gcd(p, q))}"
    if int(ans.split('/')[1]) < 0:
        print(f"{-1*int(p/math.gcd(p, q))}/{-1*int(q/math.gcd(p, q))}")
    else:
        print(ans)