_, K = map(int, input().split())
S = input()
S[:K-1] + S[K-1].lower() + S[K:]