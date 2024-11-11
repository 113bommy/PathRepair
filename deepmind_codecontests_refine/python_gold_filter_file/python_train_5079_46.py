n, d, a = [int(i) for i in input().split()]
xh = [[int(i) for i in input().split()] for _ in range(n)]
xh.sort()
da = [0] * n
r = [0] * n
ru=0

ans = 0
j=0
for i in range(n):
    da[i]+=ru
    if xh[i][1] > da[i]:
        up = (xh[i][1] - da[i]) // a
        if (xh[i][1] - da[i]) % a != 0:
            up += 1
        ans += up
        up *= a
        da[i] += up
        ru+=up
        
        while j!=n-1 and xh[j+1][0] <= xh[i][0] + 2 * d:
            j += 1
        r[j]+=up
    
    ru-=r[i]
print(ans)

