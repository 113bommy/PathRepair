MOD = 10 **9 + 7
INF = 10 ** 10

def main():
    N = int(input())
    K = 0
    for i in range(2,N + 1):
        if i*(i - 1)//2 == N:
            K = i
            break
    if K == 0:
        print('No')
        return
    ans = [[0] * (K - 1) for _ in range(K)]

    before = 1
    for i in range(K - 1):
        for j in range(i,K - 1):
            ans[i][j] = before
            ans[j + 1][i] = before
            before += 1
    print('Yes')
    print(K)
    for i in range(K):
        print(len(ans[i]),*ans[i])
if __name__ == '__main__':
    main()