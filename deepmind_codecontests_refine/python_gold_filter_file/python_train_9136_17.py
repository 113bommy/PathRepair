n = int(input())
a = list(map(int,input().split()))
x = 0
for i in range(2,n):
    x ^= a[i]
s = a[0]+a[1]
if s < x or (s-x) % 2 == 1:
    print(-1)
    exit()
d = (s-x)//2
if d & x != 0 or d > a[0]:
    print(-1)
    exit()
i = 50
ans = d
while i >= 0:
    if x >> i & 1:
        if (1 << i) + ans <= a[0]:
            ans += 1 << i
    i -= 1
if ans == 0:
    print(-1)
    exit()
print(a[0]-ans)