n = int(input())
a = list(map(int, input().split()))

money = 1000

for i in range(n-1):
    s = 0
    if a[i] < a[i + 1]:
        s = money / a[i]:
    money += (a[i + 1] - a[i]) * s
print(money)