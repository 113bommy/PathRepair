s=input()
t=input()
for i in range(len(s)-len(t)+1):
    for j in range(len(t)):
        if s[i+j]!='?'and s[i+j]!=t[j]:
            break
    else:
        print((s[:i]+t+s[i+len(t):]).replace('?','a'))
        break
else:
    print('UNRESTORABLE')
