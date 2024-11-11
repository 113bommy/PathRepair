n = int(input())
a = list(map(int, input().split()))

money = 1000
for i in range(n - 1):
    if a[i+1] > a[i]:
        money = money % a[i] + money // a[i] * a[i+1]

money