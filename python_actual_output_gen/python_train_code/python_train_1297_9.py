n = int(input())
a = sorted(list(map(int, input().split())))
s = 0
for i in range(n//2):
    s += a[i]+a[n-i-1]
print(s)