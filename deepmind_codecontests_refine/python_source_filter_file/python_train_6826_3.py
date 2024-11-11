n = int(input())
m = 0
name = ""
for i in range(n):
    handle, *t = input().split()
    plus, minus, *score = map(int, t)
    totalScore = sum(score) + 100 * plus - 50 * minus
    if totalScore > m:
        m = totalScore
        name = handle
print(name)
