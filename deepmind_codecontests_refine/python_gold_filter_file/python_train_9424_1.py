n = int(input())
ll = list(map(int,input().split()))
l = [0] * 1001
for i in range(n):
    l[ll[i]] += 1
l = sorted(l)
ans = 0
k = 0
h = 0
for i in range(1001):
    if l[i] != k:
        ans += (l[i] - k) * (1000 - i)
        k = l[i]
print(ans)