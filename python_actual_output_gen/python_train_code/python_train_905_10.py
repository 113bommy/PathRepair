n = int(input())
a = list(int(input()) for i in range(n))
s = 0
c = 0

while s != 1 and c < n:
    c += 1
    s = a[s]
if c < n:
    print(c)
else:
    print(-1)