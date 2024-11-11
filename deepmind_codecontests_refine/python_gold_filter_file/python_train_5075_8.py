n, B = map(int, input().split(' '))
a = input().split(' ')
for i in range(n):
    a[i] = int(a[i])
cost = []
count = 0
for i in range(n-1):
    if a[i]%2 == 1:
        count += 1
    else:
        count -= 1
    if count == 0:
        cost.append(abs(a[i+1]-a[i]))
s = 0
i = 0
cost = sorted(cost)
while s <= B and i < len(cost):
    s += cost[i]
    i+= 1
if i == 0:
    print(0)
else:
    if s > B:
        print(i-1)
    else:
        print(i)