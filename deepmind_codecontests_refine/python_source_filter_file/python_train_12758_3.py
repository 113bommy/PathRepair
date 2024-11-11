s=input()
if len(set(s))==1 and s[0]=='a':
    print(s[:-2]+'z')
    exit()
j=0
for i in range(len(s)):
    if s[i]=='a' and j!=0:
        print(s[i:])
        break
    else:
        if s[i]=='a':
            print(s[i],end='')
        else:
            j+=1
            print(chr(ord(s[i])-1),end='')
print()