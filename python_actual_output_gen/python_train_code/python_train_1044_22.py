s=input()
print('Yes' if s.count(s[0])==2 & len(set(s)) == 2 else 'No')