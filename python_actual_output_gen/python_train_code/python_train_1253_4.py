s=input()
print('Yes' if s[0]=='A' and 'C' in s and 1<s.index('C') and s.index('C')+1<len(s) and sum([c.isupper() for c in s])==2 else 'No')