S = input()
N = len(S)

print('First' if (N % 2 == 0) != (S[0] == S[-1]) else 'Second')
