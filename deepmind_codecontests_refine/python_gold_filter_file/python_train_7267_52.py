import sys

def I(): return int(sys.stdin.readline())
def LI(): return list(map(int, sys.stdin.readline().split()))

#実家DPと気合い遷移式

def main():
    N = I()
    a = LI()
    t = [0, 0, 0]
    for ai in a:
        t[ai-1] += 1
    A, B, C = t
    E = B+C

    dp = [[0 if (not i|j) else N/(i+j) for j in range(E+1)] for i in range(N+1)]

    for k in range(C+1):
        for j in range(E+1-k):
            for i in range(N+1-k-j):
                z = i+j+k
                if (not z):
                    continue
                d = dp[i][j]
                if (i<N):
                    dp[i+1][j] += (i+1)*d/(z+1)
                if (i>0)&(j<E):
                    dp[i-1][j+1] += (j+1)*d/z
                if (j>0)&(k<C):
                    dp[i][j-1] = (k+1)*d/z + N/z

    print(dp[A][B])

if __name__ == "__main__":
    main()