s=input()
s1=''
for i in s:
    if i=='0':
        s1+='8'
    elif i=='1':
        s1+=''
    elif i=='2':
        s1+=''
    elif i=='3':
        s1+='3'
    elif i=='4':
        s1+='6'
    elif i=='5':
        s1+='9'
    elif i=='6':
        s1+='4'
    elif i=='7':
        s1+='7'
    elif i=='8':
        s1+='0'
    elif i=='9':
        s1+='5'
if s!=s1:
    print('No')
else:
    print('Yes')
#print(' '.join([str(i) for i in a]))