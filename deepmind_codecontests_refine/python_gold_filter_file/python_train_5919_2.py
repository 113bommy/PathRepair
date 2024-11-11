n = int(input())
a = list(map(int,input().split()))
mode = 0
ans = 1
for i in range(1,n):
    d = a[i]-a[i-1]
    if mode == 0:
        mode = d
        continue
    if mode>0:
        if d<0:
            ans += 1
            mode = 0
    elif mode<0:
        if d>0:
            ans += 1
            mode = 0
print(ans)