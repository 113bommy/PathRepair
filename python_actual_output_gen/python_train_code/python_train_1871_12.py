N = int(input())
S = input()

print("Yes" if S[:2//N] == S[2//N:] else "No")