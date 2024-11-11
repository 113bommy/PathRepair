def resolve():
    N, K = map(int, input().split())
    P = list(map(int, input().split()))
    C = list(map(int, input().split()))
    for i in range(N):
        P[i] -= 1

    ans = -1e18
    for i in range(N):
        n = P[i]
        score = C[n]
        t = [score]
        while n != i:
            n = P[n]
            score += C[n]
            t.append(score)

        total = t[-1]
        l = len(t)
        for i in range(min(K, l)):
            temp_score = t[i]
            if total > 0 and K > l:
                e = int((K-(i+1))/l)
                temp_score += total*e
            ans = max(ans, temp_score)

    print(ans)


if __name__ == "__main__":
    resolve()