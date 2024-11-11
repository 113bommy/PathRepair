x = int(input())

count = 0
for y in range(1,(x+1)):
    if x%y == 0:
        count = count+1
print(count-1)
