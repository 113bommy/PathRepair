n = int(input())
lst = list(map(int, input().split()))
count = 0
sum = 0
lst.sort(reverse=True)
for i in range(len(lst)):
    if sum < n:
        sum += lst[i]
        count += 1
    else:
        continue
if sum < n :
    print('-1')
else:
    print(count)