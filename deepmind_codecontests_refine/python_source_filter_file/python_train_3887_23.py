n = int(input())
arr = list(map(int, input().split()))
sum = 0
for i in arr:
    sum = sum + i
x = sum / 2
arr.sort(reverse=True)
sum = 0
count = 0
for i in arr:
    sum = sum + i
    if sum < x:
        count = count + 1

print(count + 1)


