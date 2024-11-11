n = int(input())
count = 0
for i in range(n):
    x = int(input())
    if (x == 2):
        count += 1
    else if (x % 2 == 0):
        continue
    else:
        if (pow(2, x - 1, x) == 1):
            count += 1
print(count)
 