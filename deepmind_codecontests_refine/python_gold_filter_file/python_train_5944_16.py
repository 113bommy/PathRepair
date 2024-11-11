n = int(input())
x = list(map(int, input().split()))
for i in range(len(x)):
    if x[i] % 2 == 0:
        x[i] = x[i] - 1
print(*x)
