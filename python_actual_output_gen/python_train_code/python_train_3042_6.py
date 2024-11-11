n = int(input())
a = list(map(int, input().split()))
s = 0
for i in range(n):
    a[i] -= (i+1)

a.sort()
for i in range(n):
    s += (a[i]-a[n//2])

print(s)