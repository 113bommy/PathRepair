s=input().strip();print(s[:-1]) if '0' not in s else    print(s[:s.index('0')]+s[s.index('0')+1:])
