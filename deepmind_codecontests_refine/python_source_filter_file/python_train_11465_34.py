from math import sqrt
n = int(input())

def solve(x):
    a, b = 0, 0
    # b^2 - xb + x = 0
    D = (-x)**2 - 4*x
    if D < 0:
        print("N")
        return
    b1 = (x - sqrt(D)) / 2
    b2 = (x + sqrt(D)) / 2
    print("YES", b2, b1)

for i in range(n):
    x = int(input())
    solve(x)