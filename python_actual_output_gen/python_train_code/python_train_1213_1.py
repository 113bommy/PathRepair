N,K = map(int,input().split())
V = list(map(int,input().split()))
ans = 0
R = min(N,K)
for A in range(R+1):
    for B in range(R-A+1):
        s = V[:A]+V[N-B:]
        print(s)
        s.sort()
        S = sum(s)
        for k in range(min(K-A-B,len(s))):
            if s[k] < 0:
                S -= s[k]
        ans = max(ans,S)
print(ans)
