n, k = map(int, input().split())
lst = list(map(int, input().split()))
count = 0
for i in lst:
    if i < 5-k:
        count += 1
print(count//3)