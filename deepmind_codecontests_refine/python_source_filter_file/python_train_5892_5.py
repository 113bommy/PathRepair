n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
i = 0
m1 = float('inf')
m2 = -float('inf')
while i < n and a[i] >= 0:
    if a[i] % 2 == 1 :
        m = a[i]
    i += 1
s = sum(a[:i])
if s % 2 == 1:
    print(s)
else:
    while i < n and a[i] % 2 == 0:
        i += 1
    if i < n: m2 = a[i]
    print(max(s-m1,s+m2))