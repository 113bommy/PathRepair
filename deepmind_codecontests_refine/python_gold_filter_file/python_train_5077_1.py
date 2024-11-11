n, B = map(int, input().split())
a = list(map(int, input().split()))
even = [0] * n
odd = [0] * n
if a[0] % 2 == 0:
    even[0] = 1
else:
    odd[0] = 1
for i in range(1, n):
    if a[i] % 2 == 0:
        even[i] = even[i - 1] + 1
        odd[i] = odd[i - 1]
    else:
        even[i] = even[i - 1]
        odd[i] = odd[i - 1] + 1

rec = [0] * n
for i in range(n):
    rec[i] = even[i] - odd[i]

cost =[]
for i in range(n):
    if rec[i] == 0 and i != n - 1:
        cost.append(abs(a[i + 1] - a[i]))
cost = sorted(cost)
num = 0
j = 0
while B > 0 and j < len(cost):
    B -= cost[j]
    if B >= 0:
        num += 1
    j += 1
print(num)


