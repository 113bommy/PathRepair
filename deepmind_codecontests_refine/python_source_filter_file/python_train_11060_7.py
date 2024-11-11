import math

def YES_or_NO(n):
    i = 2
    j = 1
    if n % 4 != 0:
        print("NO")

    else:
        print("YES")

        x = int(n / 2)

        while i < n + 1:
            print(i, end=" ")
            i += 2

        while j < n - 1:
            print(i, end=" ")
            j += 2

        print((2 * int(x*(x + 1) / 2)) - (pow(x - 1, 2)))


t = int(input())

for i in range(t):
    n = int(input())
    YES_or_NO(n)
