t = int(input())

while t > 0:
    t -= 1
    a, b = [int(x) for x in input().split()]

    print(min(max(2*a, b),max(a, 2*b)) ** 2)