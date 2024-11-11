n, b, k = map(int,input().split())
array = list(map(int,input().split()))

now = 0
count = 0

for num in array:
    if num <= b:
        now += num
        if now > k:
            now = 0
            count += 1

print(count)