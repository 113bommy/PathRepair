s=input()
t=0
for i in range(len(s)):
    if s[i]=='C':
        t=i
    if s[i]=='F' and i>t:
        print('Yes')
        exit()
print('No')