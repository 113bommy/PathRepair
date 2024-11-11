N = int(input())
S = input()

if S[:N] == S[N:]:
    print("Yes")
else:
    print("No")