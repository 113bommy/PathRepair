s=input()
a=sorted(s)
print(a)
e=''
for i in range(1,len(a)):
    if(a[i-1]==a[i]):
        e+=a[i-1]
    else:
        e=''
print(e+a[-1])