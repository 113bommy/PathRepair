input()
s = input()
k = int(input())
print(''.join(c if c == s[k] else '*' for c in s))