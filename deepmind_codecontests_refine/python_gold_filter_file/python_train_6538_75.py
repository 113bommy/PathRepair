INF=float("inf")
def main():
    H,W=map(int, input().split())
    A=[input()for _ in range(H)]
    D=[[0 if A[h][w]=="#" else INF for w in range(W)] for h in range(H)]
    for h in range(H):
        for w in range(1,W):
            D[h][w]=min(D[h][w],D[h][w-1]+1)
        for w in range(W-2, -1, -1):
            D[h][w]=min(D[h][w],D[h][w+1]+1)
    for w in range(W):
        for h in range(1,H):
            D[h][w]=min(D[h][w],D[h-1][w]+1)
        for h in range(H-2, -1, -1):
            D[h][w]=min(D[h][w],D[h+1][w]+1)
    print(max(d for dd in D for d in dd))

if __name__ == "__main__":
    main()