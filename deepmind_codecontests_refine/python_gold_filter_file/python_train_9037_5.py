n = int(input())
lis = [int(input()) for i in range(n)]
if lis[0] != 0:print(-1);exit()
ans = 0
for i in range(n-1,0,-1):
    if lis[i] - lis[i-1] > 1:print(-1);exit()
    elif lis[i] - lis[i-1] == 1:ans += 1
    else:ans += lis[i]
print(ans)