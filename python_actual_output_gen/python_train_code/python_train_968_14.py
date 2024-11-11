x = min(list(map(int, input().split())))
res = 1
for i in range(2,x):
    res *= i
print(res)