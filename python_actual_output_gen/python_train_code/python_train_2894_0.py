N,x=map(int,input().split())
S = [int(i) for i in input().split()]
pre,ans = 0,0
for i in range(N):
    tmp = pre+S[i]
    if tmp > x:
        ans += tmp-x
        S[i] -= tmp-x
        pre = S[i]
print(ans)