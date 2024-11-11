n = int(input())
a = [int(i) for i in input().split()]
x = n // 2
sum = 0
for i in range(1, n):
    sum += a[i] * (abs(x - i) + i + x)
print(sum * 2)