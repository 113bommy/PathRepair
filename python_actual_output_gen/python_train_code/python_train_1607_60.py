n = int(input())
x = []
count = 0

for i in range(n):
    y = list(map(int,input().split()))
    x.append(sum(y))
if max(x) == 1 or max(x) == 0:
    print(0)

for j in range(len(x)):
    if x[j] >= 2:
        count += 1

print(count) 