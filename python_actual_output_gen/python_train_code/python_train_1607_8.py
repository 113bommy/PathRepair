n = int(input())
m = 0
result = 0
for i in range(n):
    k = list(map(int, input().split()))
    for j in range(3):
        m += k[j]
    if m > 1:
        result += 1
        m = 0
print(result)