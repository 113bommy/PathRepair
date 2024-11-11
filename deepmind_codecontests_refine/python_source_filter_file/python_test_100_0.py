n = int(input())

for _ in range(0, n):
    input()
    line = [int(i) for i in input().split()]
    line.sort()
    res = line[0]
    for i in range(0, len(line)-1):
        diff = line[i+1] - line[i]
        res = max(res, diff)

    print("ANS: ", res)