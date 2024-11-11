A, B, K = map(int, input())
S = sorted(set(list(range(A, B+1)[:K]) + list(range(A, B+1)[-K:])))
print(*S, sep="\n")
