n = int(input())
m = len(str(n))*9
if m > n:
    m = n
count = 0
values = []
for x in range(1, m+1):
    temp = str(n-x)
    temp1 = 0
    for i in temp:
        temp1 += int(i)
    if int(temp)+temp1 == n:
        count += 1
        values.append(temp)
print(count)
values.sort()
for each in values:
    print(each)