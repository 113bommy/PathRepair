
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    
    """
    dp[i][j]はi番目までで，重さ合計がjとなるときの価値の最大値にしたい．
    s<10**4　なので，jは10**4 + 10**4まで．
    ただし，上から積む時に実際には優先度がつくので，重りを適切な基準でソートすべき．
    
    現状，重さがXで，a番目とj番目を使うとして，
    「X,a,bの順番ならおけるけど，X,b,aの順だとおけない」
    という状況を考える．
    
    この時，S_j>=X+w_i かつ，s_i<X+w_j　なので．
    S_j - w_i >= X > s_i - w_j　である．
    Xを消去して移項すると，
    s_j+w_j > s_i+w_i
    
    これを基準にソートですね．
    
    """
    N=I()
    wsv=[]
    for i in range(N):
        w,s,v=MI()
        wsv.append([w,s,v])
        
    wsv.sort(key=lambda x:(x[0]+x[1]))
    
    N2=2*(10**4) +1
    dp=[[-1]*N2 for _ in range(N+1)]
    
    for i in range(N):
        w,s,v=wsv[i]
        for j in range(N2):
            dp[i+1][j]=max(dp[i][j],dp[i+1][j])
            if s>=j and j+w<=(10**4):
                dp[i+1][j+w]=max(dp[i+1][j+w],dp[i][j]+v)
                
    print(max(dp[-1]))
            
        

main()
