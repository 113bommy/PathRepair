a=input().split('WUB')
l=''
for i in range(1,len(a)):
    if(a[i]!=''):
        l+=a[i]+' '
print(l[:len(l)-1])        