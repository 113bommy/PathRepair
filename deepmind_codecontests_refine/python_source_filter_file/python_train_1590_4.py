def PowerSequence(n, sequence):
    sequence.sort()
    base = 1
    LIMIT = 10 ** 12
    Cost = LIMIT
    while True:
        NewCost = 0
        value = 1
        for i in range(n):
            if value >= LIMIT:
                value = -1
                break
            NewCost = NewCost + abs(value - sequence[i])
            value = value * base
        if value == -1 or Cost < NewCost:
            break
        Cost = NewCost
        base += 1
    return Cost


n = int(input())
listnum = [int(x) for x in input().split()]
print(PowerSequence(n, listnum))
