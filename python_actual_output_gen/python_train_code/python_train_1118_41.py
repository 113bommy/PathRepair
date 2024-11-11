A, B, K = map(int, input().split())

print("{} {}".format(max(0, A-K), min(B+A-K, B)))

