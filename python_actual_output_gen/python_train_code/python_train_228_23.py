n,m = map(int,input().split())
l = list(map(int,input().split()))
k = list(map(int,input().split()))
ans,ans2,ans3,ans4=0,0,0,0
for i in range(n):
    if l[i] % 2 == 0:
        ans += 1
    else:
        ans2 += 1
for i in range(m):
    if k[i] % 2 == 0:
        ans3 += 1
    else:
        ans4 += 1
print(min(ans,ans2) + min(ans3,ans4))
