n = int(input())
a=[]
for i in range(n):
    a += [int(input())]
a.sort()
ans = 0
for i in range(n):
    ans += a[i] * a[n-i-1]
print(ans % 10007)