def main():
    N, K = list(map(int, input().split()))
    S = [input() for _ in range(N)]
    count, strs = 0, []
    for i in range(N):
        for j in range(i+1, N):
            s = ''
            for k in range(K):
                if S[i][k] == S[j][k]:
                    s += S[i][k]
                else:
                    add = ['S', 'E', 'T']
                    add.remove(S[i][k])
                    add.remove(S[j][k])
                    s += add[0]
            strs.append(s)
    S = set(S)
    for s in strs:
        if s in S:
            count += 1
    print(count - K)

if __name__ == "__main__":
    main()
