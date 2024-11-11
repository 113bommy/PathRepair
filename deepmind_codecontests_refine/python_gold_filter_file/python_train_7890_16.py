input()
s = input()
k = int(input()) - 1
print(''.join(c if c == s[k] else '*' for c in s))