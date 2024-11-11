n = int(input())
a = map(int, input().split())
a = list(a)
a1 = [a[0]]
amazing = 0
minNumber = a[0]
maxNumber = a[0]
for i in range(n - 1):
    a1.append(a[i + 1])
    if a[i + 1] == max(a1) and maxNumber != a[i + 1] or a[i + 1] == min(a1) and minNumber != a[i + 1]:
        amazing = amazing + 1
        if a[i + 1] == max(a1):
            maxNumber = a[i + 1]
        elif a[i + 1] == min(a1):
            minNumber = a[i + 1]
print(amazing)