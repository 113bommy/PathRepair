def solve(s):
    s1 = [' *', '* ', '* ', '**', '**', '* ', '**', '**', '* ', ' *']
    s2 = ['  ', '  ', '* ', '  ', ' *', ' *', '* ', '**', '**', '* ']
    x, y = '', ''
    for ch in s:
        x += s1[ord(ch) - ord('0')]
        y += s2[ord(ch) - ord('0')]
    return x == x[::-1] and y == y[::-1]
print('Yes' if solve(input()) else 'No')
