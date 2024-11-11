def solve():
    n = int(input())
    openers = []
    bottles = []
    for i in range(n):
        a, b = map(int, input().split())
        bottles.append(a)
        openers.append(b)

    score = 0
    for i in range(n):
        for j in range(n):
            if bottles[i] == bottles[j] and i != j:
                score +=1
                break

    return n-score

print(solve())