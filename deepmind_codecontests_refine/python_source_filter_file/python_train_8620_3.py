def main()
    mod = 10**9+7
    N = int(input())
    a = [list(map(int, input().split())) for _ in range(N)]
    dp = [0]*(1<<N)
    dp[0] = 1
    def bitcount(i): # i < 2^32
        i = i - ((i >> 1) & 0x55555555)
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
        return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24
    for s in range(1, 1<<N):
        women = []
        m = bitcount(s)-1
        for w in range(N):
            if a[m][w] == 1 and s&1<<w:
                dp[s]+=dp[s^(1<<w)]
                dp[s]%=mod
    print(dp[-1])
main()