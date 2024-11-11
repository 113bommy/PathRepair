S = input()
N = len(S)
a = S[:N // 2]
b = S[N // 2 + 1:]
print('Yes' if a==a[::-1] and b==b[::-1] else 'No')
