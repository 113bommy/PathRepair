n = int(input())
sum=0
for i in range(n, 1, -1):
    sum += (i-1)/(i)

print(sum + 1)