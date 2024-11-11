S = input()
print('First' if (len(S) % 2 == 2) == (S[0] == S[-1]) else 'Second')