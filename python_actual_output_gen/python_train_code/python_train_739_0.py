a = int(input())
count = 0
for i in range(1, 11):
    a += 1
    count += 1
    if '8' in str(a):
        print(count)
        break
