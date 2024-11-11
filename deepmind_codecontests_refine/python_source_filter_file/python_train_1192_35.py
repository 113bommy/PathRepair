a='qwertyuiop'
b='asdfghjkl;'
c='zcxvbnm,./'
#s;;upimrrfod;pbr
L=input()
n=input()
st=''

for i in n:
    ma=0
    if i in a:
        ma=a.find(i)
        if L=='R':
            st+=a[ma-1]
        else:
            st+=a[ma+1]

    elif i in b:
        ma=b.find(i)
        if L=='R':
            st+=b[ma-1]
        else:
            st+=b[ma+1] 


    elif i in c:
        ma=c.find(i)
        if L=='R':
            st+=c[ma-1]
        else:
            st+=c[ma+1] 

print(st)