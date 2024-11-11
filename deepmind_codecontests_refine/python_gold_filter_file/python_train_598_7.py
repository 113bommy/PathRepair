N = int(input())

A = list(map(int, input().split()))

money = 1000

for i in range(N-1):
    t = money + (A[i + 1] - A[i]) * (money // A[i])
    money = max(money, t)

print(money)