n, m = map(int, input().split())

accums = [0]
for i in range(n - 1):
    accums.append(accums[-1] + int(input()))

result = 0
k = 0
for i in range(m):
    a = int(input())
    result += abs(accums[k + a] - accums[k])
    k += a

print(result % 100000)