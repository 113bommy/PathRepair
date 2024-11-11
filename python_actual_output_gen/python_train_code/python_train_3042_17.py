n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    a[i] -= i + 1

a.sort()

b = a[n/2]

for i in range(n):
    a[i] = abs(a[i]-b)
print(sum(a))
