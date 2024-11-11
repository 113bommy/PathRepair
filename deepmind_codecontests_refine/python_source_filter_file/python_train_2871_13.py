n = int(input())
a = list(map(int, input().split()))
for item in range(n//2):
    if item % 2 == 0:
        a[item], a[n - item-1] = a[n - item-1], a[item]
print(a)
