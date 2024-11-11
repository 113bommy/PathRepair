n = int(input())
result = 0

for i in range(1, n):
    result += i * (n - i)

result += n
print(result)