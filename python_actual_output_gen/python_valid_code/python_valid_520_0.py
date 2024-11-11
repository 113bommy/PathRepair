import sys;input=sys.stdin.readline
T, = map(int, input().split())
for _ in range(T):
    N, k = map(int, input().split())
    X = list(map(int, input().split()))
    c = len(bin(N*(N-1)))-2
    mm = 1<<(len(bin(N))-2)
    R = -10**18
    for i in range(N, max(-1, N-400), -1):
        for j in range(i-1, max(-1, N-400), -1):
            R = max(R, i*j-k*(X[i-1]|X[j-1]))
    print(R)
