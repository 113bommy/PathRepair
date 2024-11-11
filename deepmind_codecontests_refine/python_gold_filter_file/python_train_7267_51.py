def main():
    N = int(input())
    a = map(int, input().split())
    single = double = triple = 0
    for sushi in a:
        if sushi == 1:
            single += 1
        elif sushi == 2:
            double += 1
        elif sushi == 3:
            triple += 1
    dp = [[[0 for i in range(1+single+double+triple-j-k)]
           for j in range(double + triple + 1 - k)] for k in range(triple + 1)]
    for k in range(triple+1):
        for j in range(double + triple + 1-k):
            for i in range(1+single+double+triple-j-k):
                if i == 0 and j == 0 and k == 0:
                    continue
                first = second = third = 0
                if i-1 >= 0 and j >= 0 and k >= 0:
                    first = dp[k][j][i-1]
                if i+1 >= 0 and j-1 >= 0 and k >= 0:
                    second = dp[k][j - 1][i+1]
                if i >= 0 and j+1 >= 0 and k-1 >= 0:
                    third = dp[k-1][j + 1][i]
                dp[k][j][i] = (first*i + second * j +
                               third * k + N) / (i + j + k)
    print(dp[triple][double][single])


if __name__ == "__main__":
    main()
