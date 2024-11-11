n,c = list(map(int,input().split()))
xv = [list(map(int,input().split())) for i in range(n)]

frontGet = [0]*n
frontRuiseki = [0]*(n+1)
backGet = [0]*n
backRuiseki = [0]*(n+1)

for i in range(n):
    frontRuiseki[i+1] = frontRuiseki[i]+xv[i][1] 
    frontGet[i] = frontRuiseki[i+1] - xv[i][0]
    idx = -1 - i
    backRuiseki[idx-1] = backRuiseki[idx]+xv[idx][1] 
    backGet[idx] = backRuiseki[idx-1] + xv[idx][0] - c

backGet.reverse()
frontGet = [0] + frontGet
backGet = [0] + backGet
xv = [[0,0]] + xv
frontMax = [0]*(n+1)
backMax = [0]*(n+1)

for i in range(n):
    frontMax[i+1] = max(frontMax[i],frontGet[i])
    backMax[i+1] = max(backGet[i],backMax[i])

ans = max(frontMax[-1],backMax[-1],0)
for i in range(n+1):
    front = frontGet[i] - xv[i][0]
    front += backMax[n - i]
    back = backGet[i] + xv[-i][0] - c
    back += frontMax[n - i]
    ans = max(ans,front,back)
print(ans)