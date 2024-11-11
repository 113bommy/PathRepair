n = int(input())
count = 0
if n > 5:
    while n > 5:
        n -= 5
        count += 1
        if n <= 5:
            count += 1
            break
elif n <= 5:
    count += 1
print(count)