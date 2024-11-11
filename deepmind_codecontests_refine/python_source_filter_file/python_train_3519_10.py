N,K = map(int,input().split())
V = list(map(int,input().split()))
ans = 0
for i in range(min(N,K)+1): # Dequeueからとる宝石の数
    for j in range(i+1):  # 左からとる宝石の数
        Juel = V[:j]+V[N-i+j:]
        Juel.sort()
        sum_v = 0
        for k in range(min(K-i,j)):
            Juel[k] = max(Juel[k],0)
        ans = max(ans,sum(Juel))
print(ans)