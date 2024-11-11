S = input()
if 'L' in S[::2] and 'R' in S[1::2]:
    print('No')
else:
    print('Yes')
