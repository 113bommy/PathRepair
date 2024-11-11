import sys

r = sys.stdin.readline

for _ in range(int(r())):
    N, K = map(int, r().split())
    S = 0
    a = []
    N = list(map(int, list(str(N))))
    L = len(N)
    for i in range(L):
        S += N[i]
        for j in range(N[i]):
            a.append(pow(10,(L-i-1)))

    if S >= K:
        temp = 0
        idx = 0
        for i in range(S-K):
            idx = i+1
            temp += a[i]
        print(temp+a[idx], end=" ")
        for i in range(idx+1, S):
            print(a[i], end=" ")
    else:
        while S < K:
            for i in range(L-2, -1, -1):
                if N[i] != 0:
                    N[i] -= 1
                    N[i+1] += 10
                    S += 9
                    break
        a = []
        for i in range(L):
            for j in range(N[i]):
                a.append(pow(10,(L-i-1)))
        temp = 0
        idx = 0
        for i in range(S-K):
            idx = i+1
            temp += a[i]
        print(temp+a[idx], end=" ")
        for i in range(idx+1, S):
            print(a[i], end=" ")

    print()