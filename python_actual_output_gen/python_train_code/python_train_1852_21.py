s=input()
for i in s:
    if(i=='0'):
        print(s[:s.index(i)],s[s.index(i)+1:], sep='')
        exit()
print(s)