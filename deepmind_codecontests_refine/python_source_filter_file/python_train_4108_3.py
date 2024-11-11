n = int(input())
a = list(map(int, input().split()))
m = max(a)
summ = [0] * (m + 1)
maxm = [0] * (m + 1)

for i in range(n):
    summ[a[i]] += a[i]
maxm[1] = summ[1]
maxm[2] = max(summ[1], summ[2])
for i in range(3, (m + 1)):
    maxm[i] = max(summ[i] + summ[i - 2], summ[i - 1], summ[i - 3] + summ[i])
print(maxm[-1])