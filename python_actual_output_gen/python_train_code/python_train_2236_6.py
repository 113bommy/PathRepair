n = int(input())
fishki = list(map(int, input().split()))
result = [0, 0]
if n != 1:
    for i in range(n):
        if (fishki[i] % 2 == 0):
            result[0] += 1
        else:
            result[1] += 1
    print(max(result))
else:
    print(0)