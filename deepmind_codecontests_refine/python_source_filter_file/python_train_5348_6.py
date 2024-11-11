s=str(input())
s1=list(i for i in s)
for i in range(len(s1)):
    if s1[i]=='0':
        s1[i]=''
        print(''.join(s1))
        exit()
s1[0]='';
print(s1)
exit()