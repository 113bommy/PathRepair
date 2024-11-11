t = int(input())

while t > 0:
    x, y = [int(i) for i in input().split()]

    if (x < y and x == 1) or (x < y and x == 2) or (x < y and x % 2 == 1 and x == 3 * (x - 1) / 2):
        print("NO")
    else:
        print("YES")

    t -= 1