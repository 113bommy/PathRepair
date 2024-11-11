import sys
input = sys.stdin.readline

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

s = sum(a[:k])
t = 0
for i in range(k, n):
    if a[i] > 0:
        t += a[i]
ans = max(t, s + t)
# print(s, t)
for i in range(n - k):
    s -= a[i]
    s += a[k + i]
    if a[k + i] > 0:
        t -= a[k + i]
    if a[i] > 0:
        t += a[i]
    ans = max(ans, s + t, t)
    # print(s, t)
print(ans)
    
    

