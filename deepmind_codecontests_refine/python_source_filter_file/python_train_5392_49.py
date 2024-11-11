N = int(input())
S = input()
ans = "Yes "if S[:3] == S[3:] else "No"
print(ans)