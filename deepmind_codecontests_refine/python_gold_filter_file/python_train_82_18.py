from fractions import gcd
t = int(input())

for i in range(t):
    a,b,c,d = map(int, input().split())

    if a < b or b > d:
        print('No')
        continue

    if b <= c:
        print('Yes')
        continue

    g = gcd(b, d)
    if c >= b - g + (a % g):
        print('Yes')
    else:
        print('No')
