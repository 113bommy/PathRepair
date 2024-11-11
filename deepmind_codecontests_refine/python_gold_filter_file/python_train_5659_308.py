a=input()
d=''
h=''
for i in range (len(a)):
    if a[i:i+3]=='WUB':
        a=a.replace(a[i:i+3],' ')
h=a.strip(' ')
print(h)