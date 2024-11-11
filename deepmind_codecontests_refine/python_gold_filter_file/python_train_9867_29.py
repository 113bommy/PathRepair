from sys import stdin
# stdin = open('b_1.txt')

input = stdin.readline

MOD = 998244353
def main():
    A, B, C, D = map(int, input().rstrip().split())
    DP = [[0 for _ in range(D + 1)] for _ in range(C + 1)]
    for i in range(A, C + 1):
        for j in range(B, D + 1):
            if i == A and j == B:
                DP[i][j] = 1
                continue
            DP[i][j] = ((DP[i -1][j] * j) + (DP[i][j -1] * i) - (DP[i -1][j - 1] * (i - 1) * (j  - 1))) % MOD
    print(DP[C][D] % MOD)

if __name__ == "__main__":
    main()

