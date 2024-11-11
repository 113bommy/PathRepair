s = input()
n = len(s)//2
print('Yes' if s[:n]==s[n+1:][::-1] else 'No')