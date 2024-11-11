# http://codeforces.com/contest/813/problem/B
[x, y, l, r] = [int(i) for i in input().split()]
# print(x, y, l, r)
unlucky = []
x_pow = 0
while x ** x_pow < r and x > 1:
    x_pow += 1
y_pow = 0
while y ** y_pow < r and y > 1:
    y_pow += 1
for i in range(0, x_pow + 1):
    for j in range(0, y_pow + 1):
        unlucky.append(x ** i + y ** j)
unlucky.sort()
# print(unlucky)
max_golden = 0
i = 0
while i < len(unlucky) and unlucky[i] < l:
    i += 1
if i < len(unlucky) and unlucky[i] <= r:
    max_golden = max(max_golden, unlucky[i] - l - 1)
    while i + 1 < len(unlucky) and unlucky[i + 1] <= r:
        max_golden = max(max_golden, unlucky[i + 1] - unlucky[i] - 1)
        i += 1
    if i< len(unlucky):
        max_golden = max(max_golden, r - max(l, unlucky[i]))
else:
    max_golden = r - l + 1
print(max_golden)