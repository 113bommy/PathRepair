N = int(input())
S = input()

print("Yes" if S[0:N//2] == S[N//2:N] else "No")