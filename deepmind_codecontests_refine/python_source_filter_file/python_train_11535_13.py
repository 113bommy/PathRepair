import sys
def LI(): return([int(x) for x in sys.stdin.readline().split()])
def main():
    H,W = LI()
    A = [LI() for _ in range(H)]
    B = [LI() for _ in range(H)]
    D = [[abs(A[h][w]-B[h][w]) for w in range(W)] for h in range(H)]
    dp=[[0]*W for _ in range(H)]
    dp[0][0]=1<<D[0][0]<<20000

    for h in range(H):
        for w in range(W):
            if(h>0):
                dp[h][w] |= dp[h-1][w]<<D[h][w]
                dp[h][w] |= dp[h-1][w]>>D[h][w]
            if(w>0):
                dp[h][w] |= dp[h][w-1]<<D[h][w]
                dp[h][w] |= dp[h][w-1]>>D[h][w]
    for i in range(81):
        bit = 1<<(20000+i)
        bit |= 1<<(20000-i)
        if dp[H-1][W-1]&bit
            return(i)
 
if __name__ == "__main__":
    print(main())
