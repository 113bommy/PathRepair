def sieve():
    global spf, adj, MAXN
    spf[1] = 1
    for i in range(2, MAXN):
        spf[i] = i

    for i in range(2, MAXN):
        if i * i > MAXN:
            break
        if spf[i] == i:
            for j in range(i * i, MAXN, i):

                # marking spf[j] if it is not
                # previously marked
                if spf[j] == j:
                    spf[j] = i


def getdistinctFactorization(n):
    global adj, spf, MAXN
    index = 0
    for i in range(1, n + 1):
        index = 1
        x = i
        if x != 1:
            adj[i].append(spf[x])
        x = x // spf[x]
        while x != 1:
            if adj[i][index - 1] != spf[x]:
                adj[i].append(spf[x])
                index += 1
            x = x // spf[x]


if __name__ == '__main__':
    MAXN = 100001
    spf = [0 for i in range(MAXN)]
    adj = [[] for i in range(MAXN)]
    sieve()
    num = int(input())
    getdistinctFactorization(num)
    t = 0
    for i in range(1, num + 1):
        if len(adj[i]) > 1:
            t += 1
    print(t)
