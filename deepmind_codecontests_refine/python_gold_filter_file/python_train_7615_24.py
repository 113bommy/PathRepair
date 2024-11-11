import math
t = int(input())
for i in range(0, t):
    vars = list(map(int, input().rstrip().split()))
    n, k, steps= vars[0], vars[1], 0
    while n != 0:
        temp = n%k
        if temp == 0:
            n = n//k
            steps += 1
        else:
            n -= temp
            steps += temp
    print(int(steps))