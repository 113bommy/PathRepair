s = input()
t = input()
print('Yes' if s == t[:len(s)-1] else 'No')