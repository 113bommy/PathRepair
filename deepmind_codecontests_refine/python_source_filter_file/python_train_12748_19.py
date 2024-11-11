n = int(input())
count = 1
for i in range(1, n):
    count = (count+i)%n if count !=n else count
    print(count, end = ' ')

