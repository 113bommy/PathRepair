n = int(input())
a = [int(x) for x in input().split()]
long = -1
curr = 0

for i in range(n - 1):
    if a[i + 1] >= a[i]:
        curr +=1
    if a[i + 1] < a[i]:
        curr = 0

    if curr > long:
        long = curr

print(max(1, long + 1))
