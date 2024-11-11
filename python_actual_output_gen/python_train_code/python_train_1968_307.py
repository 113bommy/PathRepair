a=input()
d=''
h=''
for i in range (len(a)):
    if a[i:i+3]=='WUB':
        d=a.replace(a[i:i+3],' ')
    h=d.strip(' ')
print(h)