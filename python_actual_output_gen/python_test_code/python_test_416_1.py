n = int(input())
T = list(map(int, input().split()))
maximum = 0
result = 1
for i in range(len(T)-1):
    if T[i] < T[i+1]:
        result += 1
    else:
        result = 1
    maximum = max(result, maximum)
print(maximum)