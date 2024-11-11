n = int(input())
 
sum = 0
for i in range(n):
    sum += ((n - i - 1) * (i + 1) + 1)
print(sum)