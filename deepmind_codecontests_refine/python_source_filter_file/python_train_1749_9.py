N, K = map(int, input().split())
S = input()
print(min(sum([1 for i in range(1, N) if S[i] == S[i-1]]) + K * 2, N))