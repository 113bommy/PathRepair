import math
while True:
    n = int(input())
    if n == 0:
        break
    s = [int(i) for i in input().split(" ")]
    m = sum(s) / n
    print("{:.8f}".format(math.sqrt(sum([(x-m) ** 2 for x in s]) / n)