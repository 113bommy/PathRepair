1 N, K = map(int, input().split())
2 h = [int(input()) for i in range(N)]
3 h.sort()
4 print(min(h[i+K-1] - h[i] for i in range(N-K+1)))