import math


def solve():
    n = int(input())
    a = int(input())
    b = int(input())
    if n % 2 != 0 and a % 2 == 0 and b % 2 == 0:
        print("NO")
        return

    else:
        for x in range(n):
            k = n - a * x
            if k >= 0 and k % b == 0:
                print("YES")
                print(x, k // b)
                return
            if k < 0:
                print("NO")
                return

    print("NO")
    return


#t = int(input())
for _ in range(1):
    solve()
