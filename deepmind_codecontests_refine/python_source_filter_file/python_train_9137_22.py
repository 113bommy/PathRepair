N, P = map(int, input().split())
S = input()
U = [0]*P
ans = 0
if P == 2 or P == 5:
    for i in range(0, N):
        if int(S[i])%P == 0:
            ans += i+1
    print (ans)
else:
    t, s = 0, 1
    for i in range(0, N):
        t = (int(S[i])*s+t)%P
        U[t] += 1
        s = s*10%P
    for u in U:
        ans += u*(u-1)//2
    ans += U[0]
    print (ans)