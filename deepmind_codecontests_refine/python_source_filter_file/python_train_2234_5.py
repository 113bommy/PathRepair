n,m = map(int,input().split())
ans = 0
for i in range((n+1)//2,n):
    if i%m==0:
        ans = i
        break
if ans == 0:
    print('-1')
else:
    print(ans)