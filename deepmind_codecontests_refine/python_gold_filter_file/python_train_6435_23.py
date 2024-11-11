#!/usr/bin/env pypy3
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    K=input()
    D=I()
    N=len(str(K))
    
    #dp[i][j]はi桁目まで見て，総和のmodがj，tight&lose
    dpt=[[0]*D for _ in range(N+1)]
    dpl=[[0]*D for _ in range(N+1)]
    
    start=int(K[0])
    
    #初期化
    dpt[0][0]=1
            
    #推移
    now=0#tが0ではない位置
    
    for i in range(N):
        num=(int(K[i]))
        #t
        dpt[i+1][(now+num)%D]=1
        for k in range(num):
            dpl[i+1][(now+k)%D]+=1
        now=(now+num)%D
                    
        
        #l，尺取り
        S=0
        for j in range(10):#初期化，0~9までの和
            S+=dpl[i][j%D]
            
        for j in range(D):#あまりが10~D-1,0~9の順に配る
            dpl[i+1][(j+9)%D]+=S
            dpl[i+1][(j+9)%D]%=mod
            S+=dpl[i][(j+10)%D]-dpl[i][j%D]
        
                
    #0もカウントしているmので1ひく
    print((dpt[-1][0]+dpl[-1][0]-1)%mod)
    
    
            
    
    

main()
