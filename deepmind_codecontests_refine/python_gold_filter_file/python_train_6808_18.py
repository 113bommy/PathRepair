st=input()
new=''
i=0
while(i<len(st)):
    if st[i]=='.':
        new+=str(0)
        i=i+1
    elif st[i]=='-' and st[i+1]=='.':
        new+=str(1)
        i=i+2
    else:
        new+=str(2)
        i=i+2
print(new)