N, K = map(int, input().split())
H = sorted(map(int, input().split()))
print(sum(H[:N-K]))