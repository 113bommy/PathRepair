n = int(input())
a = [int(x) for x in input().split()]
a.sort()
total = 0
for i in range(1,n,2):
    total += a[i] - a[i-1]
print(total)