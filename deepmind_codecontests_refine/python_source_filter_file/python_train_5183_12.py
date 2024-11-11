#基本1つ飛ばしだが、パスも使える。
#奇数ならパス2回、偶数ならパス1回。
N = int(input())
A = [int(hoge) for hoge in input().split()]
DP = [[0]*3 for n in range(N)] #DP[n][y] = n桁目までみて、パスをy回使ったときの最大値

DP[0][0] = A[0]


for n in range(N):#n桁目までみる。
    #「選ぶ」か「パスを使う」かの2択。
    DP[n][0] = DP[n-2][0] + A[n]
    DP[n][1] = max((DP[n-2][1]+A[n],DP[n-1][0]))
    DP[n][2] = max((DP[n-2][2]+A[n],DP[n-1][1]))
if N%2:
    print(DP[n][2])
else:
    print(DP[n][1])