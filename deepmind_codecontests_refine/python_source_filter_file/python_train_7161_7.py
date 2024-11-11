N,T = map(int,input().split())
AB = [list(map(int,input().split())) for _ in range(N):
AB.sort(key = lambda x:x[0])
dp = [0]*(T+1)
for A,B in AB:  #それぞれの食事について
    for i in range(T-1,-1,-1):
        if A+i>=T:  #時間オーバー
            dp[T] = max(dp[T], dp[i]+B)
        else:   #時間内
            dp[i+A] = max(dp[i+A],dp[i]+B)
#これが成り立つのはAB.sortしているから
print(max(dp))
