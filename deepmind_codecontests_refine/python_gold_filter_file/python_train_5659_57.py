a=input().split('WUB')
l=''
for i in range(0,len(a)):
    if(a[i]!=''):
        l+=a[i]+' '
print(l[:len(l)-1])        