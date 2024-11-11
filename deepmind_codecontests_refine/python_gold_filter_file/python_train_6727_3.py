s=input()
c=0
d=0
p=''
for i in s:
    if i=='a'or i=='e' or i=='i' or i=='o' or i=='u':
        c=0
        d=0
        p=''
    else:
        c+=1
        if c>1:
            if p!='' and i not in p:
                d=1
        p+=i
        if c>=3 and d:
            print(' ',end='')
            c=1
            d=0
            p=i
    print(i,end='')