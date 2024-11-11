s = sorted(input())
t = sorted(input())[::-1]
print('Yes' if s[0]<t[0] else 'No')