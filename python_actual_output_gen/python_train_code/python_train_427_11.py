from collections import defaultdict
from math import sqrt
def solve():
    n = int(input())
    numbers = list(map(int, input().split(" ")))

    if n == 1:
        print(1)
        return

    amount = {}
    for number in numbers:
        if number not in amount:
            amount[number] = 1
        else:
            amount[number] += 1

    freq = defaultdict(int)
    for key, value in sorted(amount.items()):
        if key == 1:
            freq[key] += value
            continue

        freq[key] += value
        for j in range(2, int(sqrt(key)) + 1):
            if key % j == 0:
                freq[key] += value
                if key // j != j:
                    freq[key//j] += value

    highest = sorted(freq.items(), key=lambda x:x[1])[-1]

    if highest[0] == 1:
        print(1)
    else:
        print(highest[1])
solve()