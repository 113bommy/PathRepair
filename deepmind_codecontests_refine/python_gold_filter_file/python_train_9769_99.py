S = input()
print('Yes' if len(set(S[:3])) == 1 or len(set(S[1:])) == 1 else 'No')