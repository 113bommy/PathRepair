import fractions
n,m = map(int,input().split())
l = input().split()
lcm = 1
sum = 0
for i in range(len(l)):
    lcm = (int(l[i]) * lcm) // fractions.gcd(int(l[i]), lcm)
for i in range(len(l)):
    if (lcm // int(l[i])) % 2 == 1:
        sum += 1
if sum == len(l):
    x = m // (int(lcm) / 2)
    y = m // lcm
    print(int(x - y))
else:
    print(0)