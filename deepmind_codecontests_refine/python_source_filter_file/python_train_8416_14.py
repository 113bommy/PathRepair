N,x=map(int,input().split())
S = map(int,input().split())
pre,ans = 0,0
for i in range(N):
    tmp = pre+S[i]
    if tmp > x:
        ans += tmp-x
        S[i] -= tmp-x
    pre = S[i]
print(ans)