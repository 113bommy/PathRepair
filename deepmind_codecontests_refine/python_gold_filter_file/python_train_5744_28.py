n = int(input())
count = 0
for i in range(n, 10000):
    i = str(i)
    for j in range(len(i)):
        count += int(i[j])
    if count%4 == 0:
        print(i)
        break
    else:
        count = 0