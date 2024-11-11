s=input()
a=s.index('.')
v=' '
for i in range (0,a):
    v+=s[i]
if(s[a-1]=='9'):
    print('GOTO vasilisa.')
else:
    if(int(s[a+1])>=5):
        print(int(v)+1)
    else:
        print(int(v))