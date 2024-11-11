N, K = list(map(int, input().split()))
H = list(map(int, input().split()))

print(sorted(H)[::-1][K:])