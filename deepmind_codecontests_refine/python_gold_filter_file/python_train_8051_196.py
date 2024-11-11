n = int(input())
sum = 0
a = list(map(int, input().split()))
for i in range(n):
    sum += a[i]
print(str(sum / n))
