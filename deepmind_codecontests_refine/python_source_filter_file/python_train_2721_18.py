R = lambda: map(int, input().split())
n = int(input())
L = list(R())
p,n = 0,0
for i in L:
    if i > 0:
        p += 1
    elif i < 0:
        n += 1
h = (n+1)//2
if p > n and p >= h:
    print(1)
elif p < n and n >= h:
    print(-1)
else:
    print(0)