s,limit  = map(int,input().split())
ans = []
for i in range(limit,0,-1):
    if s-(i&-i) >=0:ans.append(i);s-=(i&-i)
if sum == 0:
    print(len(ans))
    print(" ".join(map(str, ans)))
else:
    print(-1)