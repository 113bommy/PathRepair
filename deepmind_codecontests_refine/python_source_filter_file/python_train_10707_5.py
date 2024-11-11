N = int(input())
a = sorted(list(map(int, input().split())))
count = 1
for i in range(N-1):
    if a[i] != a[i-1]:
        count += 1
if count % 2 == 0:
    count -= 1
print(count)