S = input()

print("Yes" if ('R' not in S[0::2] and 'L' not in S[1::2]) else "No")