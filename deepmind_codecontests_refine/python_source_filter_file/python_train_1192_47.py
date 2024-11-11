k='qwertyuiopasdfghjkl;zxcvbnm,./'
c=input()
s=input()
if c=='R':
    for i in s:
        print(k[k.index(i)-1],end='')
else:
    for i in s:
        print(k[k.index(i)+1])