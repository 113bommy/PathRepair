N = int(input())

x = list(map(int, input().split()))
x.sort

y = x[0]
for i in x[1:]:
    y = (y + i) / 2
print(y)
