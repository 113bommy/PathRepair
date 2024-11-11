import math
from collections import defaultdict
def solve():
    n = int(input())
    arr = list(map(int, input().split(" ")))

    freq = defaultdict(int)
    total = 0

    power_of_twos = []
    count = 1
    while 2**count <= 2 * 10**9:
        power_of_twos.append(2**count)
        count += 1

    for i in arr:
        if i in freq:
            total += freq[i]

        for j in power_of_twos:
            if j - i > 0:
                freq[j - i] += 1

    print(total)

solve()