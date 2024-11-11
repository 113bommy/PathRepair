H, W, A, B = map(int, open(0).read().split())

S = [["01"[(i < B) ^ (j < A)] for i in range(H)] for j in range(W)]

print("\n".join("".join(s) for s in S))
