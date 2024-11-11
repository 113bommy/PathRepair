import fractions
a, b, c, d = map(int, input().split())
lcm = int(c*d/fractions.gcd(c, d))
ans = (b-b//c-b//d+b//lcm)-(a-a//c-a//d+a//lcm)
print(ans)
