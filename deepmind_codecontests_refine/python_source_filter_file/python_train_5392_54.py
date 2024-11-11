N = int(inoput())
S = input()

print('Yes' if S[N//2:] == S[:N//2] else 'No')