n = int(input())

arr = list(map(lambda x:int(x), input().split()))

count_odd = 0
count_even = 0
total = 0
for num in arr:
    if num % 2 == 0:
        count_even += 1
    else:
        count_odd += 1
    total += num

if total % 2 == 0:
    print(count_odd)
else:
    print(count_even)