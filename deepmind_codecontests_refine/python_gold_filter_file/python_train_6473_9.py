n = int(input())
x = list(map(int, input().split()))
output = 0
for i in range(n):
    if x[i] % 2 == 0:
        output += 1
print(min(output, n - output))