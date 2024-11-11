n, k = map(int, input().split()) #кол-во ребят и требуемое кол-во раз
info = list(map(int, input().split()))
counter = 0
for i in range(n):
    info[i] *= k
    if info[i] <= 5:
        counter += 1
print(counter // 3)