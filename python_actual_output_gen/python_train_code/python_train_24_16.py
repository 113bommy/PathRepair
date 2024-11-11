n, k = [int(x) for x in input().split()]
ai = dict((int(x), True) for x in input().split())


for i in reversed(range(1, k//2 + 1)):
    if k % i == 0 and i in ai:
        print(k // i)
        exit()
