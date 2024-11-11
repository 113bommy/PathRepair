for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    countAlice, countBob, totalOperation = 0, 0, 0
    prev = 0
    while len(a) > 0:
        totalOperation += 1
        if totalOperation % 2 == 0:
            now = a.pop(len(a) - 1)
        else:
            now = a.pop(0)
        while now <= prev:
            if not len(a):
                break
            if totalOperation % 2 == 0:
                now += a.pop(len(a) - 1)
            else:
                now += a.pop(0)
        prev = now
        if totalOperation % 2 == 0:
            countAlice += prev
        else:
            countBob += prev
    print(totalOperation, countBob, countAlice)
