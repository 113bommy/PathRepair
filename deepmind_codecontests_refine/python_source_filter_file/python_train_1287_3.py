n = int(input())

list = input().split()
sum = 0
for i in range(len(list)):
    sum += int(list[i])

if sum % 2 == 0:
    print(n)
else:
    print(n-1)