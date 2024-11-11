S=map(int, input().split())
S.sort()
print(S[0] if S[1] == S[2] else S[2])