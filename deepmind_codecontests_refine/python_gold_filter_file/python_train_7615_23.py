n = int(input())
for i in range(n):
    x, k = [int(x) for x in input().split()]
    numSteps = 0
    while x != 0:
        remainder = int(x%k)
        if remainder == 0:
            x = x//k
            numSteps += 1
        else:
            x = x-remainder
            numSteps += remainder

    print(int(numSteps))
