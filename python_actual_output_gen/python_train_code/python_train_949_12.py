R = lambda: map(int, input().split())
n = int(input())
L = list(R())
p,ne = 0,0
for i in L:
    if i > 0:
        p += 1
    elif i < 0:
        ne += 1
h = (n+1)//2
if p > ne and p >= h:
    print(1)
elif p < ne and ne >= h:
    print(-1)
else:
    print(0)