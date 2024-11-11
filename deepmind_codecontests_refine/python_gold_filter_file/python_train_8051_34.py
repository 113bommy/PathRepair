x = int(input())

p = input().split()

total = 0

for i in range(x):
    total += int(p[i])
    i+=1

fraction = total/100

percent = 100*fraction/x

print(percent)
