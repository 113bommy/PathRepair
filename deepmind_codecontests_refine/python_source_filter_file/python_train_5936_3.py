def lcs(s1, s2):
    dp = []
    for s2_k in s2:
        bgn_idx = 0
        for i, cur_idx in enumerate(dp):
            chr_idx = s1.find(s2, bgn_idx) + 1
            if not chr_idx:
                break
            dp[i] = min(cur_idx, chr_idx)
            bgn_idx = cur_idx
        else:
            chr_idx = s1.find(s2, bgn_idx) + 1
            if chr_idx:
                dp.append(chr_idx)
    return len(dp)

def solve():
    N = int(input())
    for _ in range(N):
        x = input()
        y = input()
        print(lcs(x, y))

if __name__ == '__main__':
    solve()