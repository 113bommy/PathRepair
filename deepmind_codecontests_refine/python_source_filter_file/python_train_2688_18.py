import fractions
n, m = map(int, input().split())
s = input()
t = input()
l = fractions.gcd(n, m)
a, b = n//l, m//l
for i in range(l):
    if t[b*i] != s[a*i]:
        print(-1)
        exit()
print(n*m)