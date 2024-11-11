N = int(input())//2
S = input()
ans = "Yes "if S[:N] == S[N:] else "No"
print(ans)