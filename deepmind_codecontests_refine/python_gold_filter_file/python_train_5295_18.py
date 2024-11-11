S = input()
N = len(S)

print('First' if (N % 2 == 1) ^ (S[0] == S[-1]) else 'Second')
