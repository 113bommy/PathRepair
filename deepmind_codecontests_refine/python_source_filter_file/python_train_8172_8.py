ls = [0]*2010
ld = [0]*2010
n = int(input())
for _ in range(n):
    x,y = map(int,input().split())
    ls[x+y] += 1
    ld[x-y] += 1
ans = 0
for i in range(1010):
    if ls[i]!=0:
        ans += ls[i]*(ls[i]-1)//2
    elif ld[i]!=0:
        ans += ld[i]*(ld[i]-1)//2
print(ans)