n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
total = 0
for i in range(n-1):
    total += a[i]
print(total)
