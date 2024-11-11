n = int(input())

sum = 0
for num in input().strip().split():
    sum += float(num)/100

print((sum/4)*100)