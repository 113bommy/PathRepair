s = input()
for i in range(len(s)-1,-1,-1):
    if(s[i] == '0'):
        print(s[:i]+s[i+1:])
        exit()
print(s[1:])
