N = int(input())//2
S = input()

print('Yes' if S[:N] == S[N:] else 'No')