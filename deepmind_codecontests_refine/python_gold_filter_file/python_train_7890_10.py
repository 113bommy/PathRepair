input()
s = input()
k = int(input())
print(''.join(c if c == s[k-1] else '*' for c in s))