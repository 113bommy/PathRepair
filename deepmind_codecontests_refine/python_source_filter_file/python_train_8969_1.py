import sys
input = sys.stdin.readline

Q = int(input())

def calc(n, k, X):
    if (sum(X)-k) % 2:
        print("NO")
        return 0
    ANS = []
    if n == 1:
        print("YES")
        print(1)
        return 0
    for i in range(N-1):
        if X[i] % 2:
            ANS.append(i+1)
            if len(ANS) == k-1:
                print("YES")
                print(*ANS, n)
                return 0
    else:
        print("NO")

for _ in range(Q):
    N, K = map(int, input().split())
    calc(N, K, [int(a) for a in input().split()])

