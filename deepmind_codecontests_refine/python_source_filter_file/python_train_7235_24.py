n = int(input())
b = [int(x) for x in input().split()]
result = b[0]
for i in range(1, n):
    result += abs(b[i]-b[i-1])
print(result)
