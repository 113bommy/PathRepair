s = 'a' + input()
sum(min((ord(s[i+1])-ord(s[i])) % 26, (ord(s[i])-ord(s[i+1])) % 26) for i in range(len(s)-1))