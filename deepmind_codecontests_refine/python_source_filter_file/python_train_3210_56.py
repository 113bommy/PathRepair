A, B, K = map(int, input().split())
K = min(K, B - A + 1)
print(*list(set([i for i in range(A, A+K)] + [i for i in range(B-K+1, B+1)])), sep='\n')