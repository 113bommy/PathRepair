""""
10 10


20 10
0 10


40 10
20 10
0 10


45 10
25 10
5 10
5 0




"""

a, b = map(int, input().split())

while a > 0 and b > 0:
    if a >= 2*b:
        c = 2*b
        a = a % c

    elif b > 2*a:
        c = 2 * a
        b = b % c

    else:
        break

print(a, b)

