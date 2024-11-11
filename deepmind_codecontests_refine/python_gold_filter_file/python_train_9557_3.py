N = int(input())
n = 1<<N.bit_length()-1
if N == n:
    print("No")
else:
    print("Yes")
    # print(n)
    ANS = []
    if N % 2:
        for i in range(1, n-1):
            ANS.append((i, i+1))
        ANS.append((n-1, N+1))
        for i in range(1, n-1):
            ANS.append((i+N, i+N+1))
        for i in range(0, N-n, 2):
            ANS.append((1+N, i+n))
            ANS.append((i+n, i+n+1))
            ANS.append((1+N, i+n+1+N))
            ANS.append((i+n+1+N, i+n+N))
    else:
        a, b, c = N-2, N-1, N
        X = [i for i in range(1, n) if i != a^c] + [c, a]
        # print("X =", X)
        for i in range(n-1):
            ANS.append((X[i], X[i+1]))
        ANS.append((X[n-1], X[0]+N))
        for i in range(n-1):
            ANS.append((X[i]+N, X[i+1]+N))
        for i in range(0, N-n-3, 2):
            ANS.append((1+N, i+n))
            ANS.append((i+n, i+n+1))
            ANS.append((1+N, i+n+1+N))
            ANS.append((i+n+1+N, i+n+N))
        ANS.append((a, a^c))
        ANS.append((c, (a^c)+N))
        ANS.append((1+N, b))
        ANS.append((a, b+N))
    # print(len(ANS))
    # print(ANS)
    if N == 3:
        ANS = [(1,2),(2,3),(3,4),(4,5),(5,6)]
    for ans in ANS:
        print(*ans)
    # print("len =", len(ANS))